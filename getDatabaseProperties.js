import { config } from "dotenv"

config();

const databaseId = process.env.DATABASE_ID
const notionApiKey = process.env.NOTION_API_KEY

// 노션 API를 호출하여 데이터베이스 프로퍼티를 조회하는 함수
async function getDatabaseProperties() {
    const url = `https://api.notion.com/v1/databases/${databaseId}`;
    const headers = {
        'Authorization': `Bearer ${notionApiKey}`,
        'Content-Type': 'application/json',
        'Notion-Version': '2022-06-28'
    };

    try {
        const response = await fetch(url, { method: 'GET',
            headers 
        }).then((response)=> {return response.json()})
        .then((result)=> {
            return result;
        });
        const properties = response.properties;
        
        console.log("Database Properties:");
        for (const [propName, propInfo] of Object.entries(properties)) {
            console.log(`${propName}: ${JSON.stringify(propInfo, null, 2)}`);
        }
    } catch (error) {
        console.error(`Failed to retrieve database properties. Status code: ${error.response.status}`);
        console.error(error.response.data);
    }
}

// 스크립트를 실행합니다.
getDatabaseProperties();
