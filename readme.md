## ⚙️ 노션 페이지 생성 자동화 프로젝트

github repo에 push하면, 해당 내용을 담아서 노션에 페이지를 자동으로 생성합니다.

<br/>

## 💻 사용 기술 및 개발 과정

<img src="https://img.shields.io/badge/GitHub%20Actions-2088FF?style=for-the-badge&logo=github-actions&logoColor=white" alt="GitHub Actions Badge"> <img src="https://img.shields.io/badge/Notion-000000?style=for-the-badge&logo=notion&logoColor=white" alt="Notion Badge"> <img src="https://img.shields.io/badge/Typescript-3178C6?style=for-the-badge&logo=Typescript&logoColor=white"/>

  1. github action으로 push 감지하고 커밋 내용을 읽어 필요한 정보를 변수에 저장합니다.
  2. 변수에 저장된 내용을 담아 노션 페이지를 생성하는 API를 요청합니다.
  3. 노션에는 데이터베이스에 한페이지로 커밋 내용을 담은 페이지가 생성됩니다.

<br/>

## ‼️ 커밋 형식

[티어] 문제이름 문제출저(링크)
