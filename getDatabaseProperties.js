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




// Database Properties:
// 티어: {
//   "id": "tVrh",
//   "name": "티어",
//   "type": "select",
//   "select": {
//     "options": [
//       {
//         "id": "`>Dw",
//         "name": "플레1",
//         "color": "blue",
//         "description": null
//       },
//       {
//         "id": "}[Yn",
//         "name": "플레2",
//         "color": "blue",
//         "description": null
//       },
//       {
//         "id": "UlaD",
//         "name": "플레3",
//         "color": "blue",
//         "description": null
//       },
//       {
//         "id": ":d?b",
//         "name": "플레4",
//         "color": "blue",
//         "description": null
//       },
//       {
//         "id": "g>=X",
//         "name": "플레5",
//         "color": "blue",
//         "description": null
//       },
//       {
//         "id": "jgYw",
//         "name": "브론즈1",
//         "color": "brown",
//         "description": null
//       },
//       {
//         "id": "iGL?",
//         "name": "골드5",
//         "color": "yellow",
//         "description": null
//       },
//       {
//         "id": "=vPo",
//         "name": "골드4",
//         "color": "yellow",
//         "description": null
//       },
//       {
//         "id": "N`Ji",
//         "name": "골드3",
//         "color": "yellow",
//         "description": null
//       },
//       {
//         "id": "PdB;",
//         "name": "골드2",
//         "color": "yellow",
//         "description": null
//       },
//       {
//         "id": "DP^\\",
//         "name": "골드1",
//         "color": "yellow",
//         "description": null
//       },
//       {
//         "id": "qYcD",
//         "name": "실버5",
//         "color": "gray",
//         "description": null
//       },
//       {
//         "id": "oXN?",
//         "name": "실버4",
//         "color": "gray",
//         "description": null
//       },
//       {
//         "id": "Rj?\\",
//         "name": "실버3",
//         "color": "gray",
//         "description": null
//       },
//       {
//         "id": "RKen",
//         "name": "실버2",
//         "color": "gray",
//         "description": null
//       },
//       {
//         "id": "^baj",
//         "name": "실버1",
//         "color": "gray",
//         "description": null
//       }
//     ]
//   }
// }
// 날짜: {
//   "id": "~Bqb",
//   "name": "날짜",
//   "type": "date",
//   "date": {}
// }
// 문제: {
//   "id": "title",
//   "name": "문제",
//   "type": "title",
//   "title": {}
// }