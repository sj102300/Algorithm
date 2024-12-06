import { Client } from "@notionhq/client"
import { config } from "dotenv"
import { Tier, getTier } from './getTier.ts';

config();

const notion = new Client({ auth: process.env.NOTION_API_KEY });
const databaseId = process.env.DATABASE_ID;
const commitMessage = process.env.COMMIT_MESSAGE;
let changedFilesContents = process.env.CHANGED_FILES_CONTENTS;

// const commitMessage = "[Bronze3] https://www.acmicpc.net/problem/2178";
// const changedFilesContents = "const a=b;"

interface Info {
    tier: Tier;
    problemTitle: string;
    problemUrl: string;
}

function extractInfo(text: string) {
    let match = text.match(/\[(.*?)\]/); // 정규 표현식, []안의 문자열 뽑아냄
    let problem = text.split(' ');
    let result: Info = {
        tier: match ? getTier(match[1]): { name: '오류', icon: { type: 'external', external: { url: 'https://upload.wikimedia.org/wikipedia/commons/5/5f/Red_X.svg' } } },
        problemTitle: problem[1],
        problemUrl: problem[2] || 'https://www.acmicpc.net/'
    }
    return result;
}


async function addItem(databaseId: string) {

    let today: string = new Date().toISOString();

    if (!commitMessage){
        console.log('커밋 메시지를 읽을 수 없습니다!');
        console.log(commitMessage);
        return;
    }
    if (commitMessage[0] !== "["){
        console.log('노션 페이지 생성 관련 커밋이 아닙니다.');
        return;
    }
    if (!changedFilesContents){
        console.log('파일 내용을 읽을 수 없습니다!');
        console.log(changedFilesContents);
        changedFilesContents = commitMessage;
    }
    let info: Info = extractInfo(commitMessage)

    if (info) {
        console.log(info);

        const newPage = await notion.pages.create({
            parent: {
                database_id: databaseId,
            },
            icon: info.tier.icon,
            properties: {
                "문제": {
                    type: "title",
                    title: [{ type: "text", text: { content: info.problemTitle } }],
                },
                "날짜": {
                    type: "date",
                    date: { start: today },
                },
                "티어": {
                    type: "select",
                    select: {
                        name: info.tier?.name,
                    }
                }
            },
            children: [
                {
                    object: 'block',
                    type: "bulleted_list_item",
                    bulleted_list_item: {
                        rich_text: [{
                            type: "text",
                            text: {
                                "content": "문제 링크",
                                "link": null
                            }
                        }],
                        children: [
                        {
                            type: "bookmark",
                            bookmark: { 
                                url: info?.problemUrl
                            }
                        },
                        {
                            type: "paragraph",
                            paragraph: {
                                rich_text: [{
                                    type: "text",
                                    text: {
                                        content: ''
                                    }
                                }],
                            }
                        }
                    ]},
                },
                {
                    object: 'block',
                    type: "bulleted_list_item",
                    bulleted_list_item: {
                        rich_text: [{
                            type: "text",
                            text: {
                                "content": "문제 풀이 방식",
                                "link": null
                            }
                        }],
                        children: [
                            {
                                type: "paragraph",
                                paragraph: {
                                    rich_text: [{
                                        type: "text",
                                        text: {
                                            content: ''
                                        }
                                    }],
                                }
                            }
                        ]
                    }
                },
                {
                    object: 'block',
                    type: "bulleted_list_item",
                    bulleted_list_item: {
                        rich_text: [{
                            type: "text",
                            text: {
                                "content": "최종 코드",
                                "link": null
                            }
                        }],
                        children: [
                        {
                            type: "code",
                            code: {
                                "caption": [],
                                "rich_text": [{
                                    "type": "text",
                                    "text": {
                                        "content": changedFilesContents
                                    }
                                }],
                                "language": "python"
                            }
                        },
                        {
                            type: "paragraph",
                            paragraph: {
                                rich_text: [{
                                    type: "text",
                                    text: {
                                        content: ''
                                    }
                                }],
                            }
                        }
                    ]}
                },
                {
                    object: 'block',
                    type: "bulleted_list_item",
                    bulleted_list_item: {
                        rich_text: [{
                            type: "text",
                            text: {
                                "content": "후기 및 느낀점",
                                "link": null
                            }
                        }],
                        children: [
                            {
                                type: "paragraph",
                                paragraph: {
                                    rich_text: [{
                                        type: "text",
                                        text: {
                                            content: ''
                                        }
                                    }],
                                }
                            }
                        ]
                    }
                },
            ],
        });
        console.log(newPage)
    }
}

databaseId ? addItem(databaseId) : console.log('database_id를 찾을 수 없습니다!')
