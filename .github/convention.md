# Trunk-Based Development 컨벤션

## 소개

이 저장소는 Trunk-Based Development (TBD)를 따르는 프로젝트에 대한 규칙과 가이드라인을 기술합니다.
TBD는 주로 긴 브랜치 수명을 피하고 대신 메인 브랜치(트렁크)를 사용하여 빠른 통합을 지향하는 개발 방법론입니다.

## 브랜치 전략

### 메인 브랜치

- `main` 브랜치는 항상 배포 가능한 상태를 유지해야 합니다.
- 모든 개발은 `main` 브랜치에서 진행되어야 합니다.

### feature 브랜치

- 새로운 기능 추가는 `main`에서 새로운 브랜치를 생성하여 진행합니다.
- 브랜치 이름은 `feature/(issue_number)-기능이름` 형식을 따라야 합니다.

### bugfix 브랜치

- 버그 수정은 `main`에서 새로운 브랜치를 생성하여 진행합니다.
- 브랜치 이름은 `bugfix/(issue_number)-버그이름` 형식을 따라야 합니다.

### modify 브랜치

- 코드 수정은 `main`에서 새로운 브랜치를 생성하여 진행합니다.
- 브랜치 이름은 `modify/(issue_number)-수정이름` 형식을 따라야 합니다.

## 커밋 메시지

- 커밋 메시지는 명확하고 간결해야 합니다.
- 각 커밋 메시지는 제목과 본문으로 나누어져야 합니다.
- 제목은 명령조로 시작하며, 50자 이내로 작성합니다.
- 본문은 변경 사항에 대한 자세한 설명을 포함하며, 필요에 따라 생략 가능합니다.

## 코드 리뷰

- 모든 코드 변경은 Pull Request를 통해 이루어져야 합니다.
- 최소한 한 명의 리뷰어가 코드 변경을 승인해야 합니다.

## 머지 정책

- 트렁크로부터 브랜치로의 머지는 빈번하게 이루어져야 합니다.
- 머지 충돌이 발생하면 빠르게 해결해야 합니다.

## 기타 사항

- 단위 테스트와 통합 테스트는 필수적으로 작성되어야 합니다.
- CI/CD 파이프라인을 설정하여 자동화된 빌드 및 배포를 수행합니다.

## 참고 자료

- [Trunk-Based Development 소개](https://trunkbaseddevelopment.com/)
- [GitHub Flow](https://guides.github.com/introduction/flow/)
