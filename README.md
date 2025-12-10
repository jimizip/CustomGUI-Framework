# CustomGUI Framework & Applications

**순수 Win32 API 기반 커스텀 GUI 프레임워크 및 애플리케이션**

외부 라이브러리 없이 Win32 API만을 활용하여 개발한 객체지향 GUI 프레임워크와 이를 활용한 Calculator, Painter 애플리케이션입니다.

## 🏆 주요 기술 성과

### [프레임워크 개발] 
외부 라이브러리 없이 Win32 API만을 활용하여 윈도우 생성, GDI 드로잉, 컨트롤 제어가 가능한 **커스텀 GUI 라이브러리 설계**

### [구조 개선] 
절차지향적 Win32 API를 클래스로 래핑하여 **객체지향 구조로 재설계**, 개발 생산성 및 코드 재사용성 향상

### [디자인 패턴] 
Observer/Listener 패턴을 적용해 **마우스/키보드 이벤트 감지부와 비즈니스 로직을 분리**, 윈도우 메시지 루프 동작 원리 완벽 이해

### [아키텍처 설계]
Win32 메시지 기반 이벤트를 객체지향 이벤트 시스템으로 추상화하여 **확장 가능한 GUI 애플리케이션 구조** 구현

## 📋 프로젝트 구성

이 프로젝트는 세 개의 주요 컴포넌트로 구성되어 있습니다:
- **MyGuiLib**: 커스텀 GUI 프레임워크 라이브러리
- **Calculator**: GUI 프레임워크를 활용한 계산기 애플리케이션 
- **Painter**: 벡터 기반 그림 그리기 애플리케이션

## 🏗️ 프로젝트 구조

```
Project2021/
├── MyGuiLib/          # GUI 라이브러리
│   ├── frame.h/.cpp   # 메인 윈도우 프레임
│   ├── Component.h/.cpp # GUI 컴포넌트 기본 클래스
│   ├── button.h/.cpp  # 버튼 컴포넌트
│   └── ActionListener.h/.cpp # 이벤트 리스너
├── Calculator/        # 계산기 애플리케이션
│   ├── main.cpp       # 진입점
│   ├── CalcFrame.h/.cpp # 계산기 메인 프레임
│   ├── CalcButton.h/.cpp # 계산기 버튼
│   └── CalcLabel.h/.cpp # 계산기 디스플레이
└── Painter/          # 페인터 애플리케이션
    ├── main.cpp      # 진입점
    ├── PainterFrame.h/.cpp # 페인터 메인 프레임
    ├── figure.h/.cpp # 도형 기본 클래스
    ├── Rect.h/.cpp   # 사각형 클래스
    ├── Ellip.h/.cpp  # 타원 클래스
    └── Line.h/.cpp   # 직선 클래스
```

## 🔧 빌드 요구사항

- **개발 환경**: Visual Studio 2019 이상
- **플랫폼**: Windows (x86/x64)
- **언어**: C++
- **GUI 라이브러리**: Windows API

## 🚀 실행 방법

### Visual Studio에서 실행
1. `Project2021.sln` 파일을 Visual Studio에서 열기
2. 솔루션 탐색기에서 실행할 프로젝트 선택:
   - `Calculator`: 계산기 실행
   - `Painter`: 페인터 실행
3. 시작 프로젝트로 설정 (우클릭 → "시작 프로젝트로 설정")
4. F5 또는 Ctrl+F5로 실행

### 빌드된 실행 파일로 실행
```bash
# Debug 폴더에서 실행
./Debug/Calculator.exe  # 계산기 실행
./Debug/Painter.exe     # 페인터 실행
```

## 🎮 주요 기능

### Calculator (계산기)
- 기본 계산 기능
- Apple/Banana 타입 선택 기능
- GUI 기반 사용자 인터페이스

### Painter (그림 그리기)
- **도형 그리기**: 
  - 사각형 (Rectangle)
  - 타원 (Ellipse) 
  - 직선 (Line)
- **도형 편집**:
  - 선택 및 이동
  - 그룹화 기능
- **마우스 인터랙션**: 드래그로 도형 생성

## 🏗️ 프레임워크 아키텍처

### 📐 Win32 API 래핑 구조
```
Win32 API (절차지향)          →    CustomGUI Framework (객체지향)
─────────────────────────────────────────────────────────────────
WNDPROC WndProc()            →    Frame::eventHandler()
WPARAM, LPARAM               →    MyEvent (추상화된 이벤트)  
GetMessage(), DispatchMessage() →  Frame::run() (메시지 루프)
HDC, GDI functions           →    Component::draw() (그리기 추상화)
```

### 🔄 이벤트 처리 플로우
```
1. Win32 Message → 2. WndProc() → 3. MyEvent 변환 → 4. Frame::eventHandler()
                                                           ↓
5. ActionListener::*Performed() ← 4. Component::onClick() ← 3. 이벤트 전달
```

### 📚 핵심 클래스 구조

#### MyGuiLib (GUI 프레임워크)
- **`Frame`**: 윈도우 프레임 기본 클래스
  - Win32 윈도우 생성/관리
  - 메시지 루프 처리 (`run()`)
  - 이벤트 라우팅 (`eventHandler()`)
  - 컴포넌트 관리 (`add()`, `repaint()`)

- **`Component`**: GUI 컴포넌트 기본 클래스
  - 위치/크기 관리 (`setBounds()`)
  - 마우스 히트 테스트 (`inside()`) 
  - 그리기 인터페이스 (`draw()`)
  - 이벤트 콜백 (`onClick()`)

- **`ActionListener`**: Observer 패턴 이벤트 리스너
  - `ShapePerformed()`: 도형 관련 이벤트
  - `CalcPerformed()`: 계산기 관련 이벤트  
  - `MenuPerformed()`: 메뉴 관련 이벤트

- **`MyEvent`**: Win32 메시지 래핑 클래스
  - Windows 메시지를 객체지향으로 추상화
  - 마우스/키보드 이벤트 감지 메서드 제공
  - 좌표 정보 추출 (`getPos()`, `getX()`, `getY()`)

#### 도형 시스템 (Painter)
- **`Figure`**: 모든 도형의 기본 추상 클래스
  - 순수 가상함수 `draw(HDC)` 정의
  - 좌표 정규화 (`normalize()`)
  - 이동 연산 (`move()`)
  - 포함 검사 (`inside()`)

- **도형 구현 클래스**:
  - `Rect`: 사각형 (Rectangle API 래핑)
  - `Ellip`: 타원 (Ellipse API 래핑)  
  - `Line`: 직선 (MoveTo/LineTo API 래핑)
  - `Group`: 복합 도형 (Composite 패턴)

## 🛠️ 기술 스택

- **언어**: C++
- **GUI**: Windows API
- **개발도구**: Visual Studio
- **빌드시스템**: MSBuild

## 💡 핵심 설계 원리

### 🎨 객체지향 설계 패턴
- **상속**: `Frame` ← `CalcFrame`, `PainterFrame` 전문화
- **다형성**: `Figure::draw()` 순수 가상함수로 도형별 렌더링 분기
- **캡슐화**: Win32 API 복잡성을 클래스 내부로 은닉
- **Composite 패턴**: `Group` 클래스로 도형 계층구조 관리
- **Observer 패턴**: `ActionListener`로 이벤트 처리 분리

### ⚡ 메시지 루프 동작 원리
```cpp
// Win32 메시지 → 객체지향 이벤트 변환 과정
LRESULT CALLBACK WndProc(HWND, UINT msg, WPARAM wParam, LPARAM lParam) {
    // 1. Windows 메시지 수신
    MyEvent event(msg, wParam, lParam);  // 2. 객체로 래핑
    mainWindow->eventHandler(event);     // 3. 프레임으로 전달
    return DefWindowProc(...);
}

void Frame::eventHandler(MyEvent e) {
    Component* target = findMenu(e.getPos());  // 4. 히트 테스트
    if (target) target->onClick(e);           // 5. 컴포넌트 이벤트 발생
}
```

## 🎯 학습 성과

### 시스템 프로그래밍 이해
- **Win32 API**: 윈도우 생성, 메시지 처리, GDI 드로잉 완전 이해
- **메모리 관리**: 동적 객체 생성/소멸, 스마트 포인터 미적용 환경에서의 안전한 메모리 관리
- **이벤트 아키텍처**: 콜백 함수에서 객체지향 이벤트 시스템으로의 패러다임 전환

### 객체지향 프로그래밍 심화
- **프레임워크 설계**: 재사용 가능한 GUI 라이브러리 아키텍처 구축
- **API 래핑**: 절차지향 API를 객체지향으로 추상화하는 설계 기법
- **디자인 패턴 실전 적용**: Observer, Composite 패턴의 실무 활용

### 소프트웨어 공학
- **모듈화**: 라이브러리와 애플리케이션의 명확한 분리
- **확장성**: 새로운 도형이나 컴포넌트 추가가 용이한 구조
- **코드 재사용**: 공통 GUI 프레임워크로 Calculator/Painter 구현

## 📝 주의사항

- Windows 환경에서만 실행 가능
- Visual Studio 2019 이상 권장
- 한글 문자열 처리를 위해 유니코드 설정 필요

## 🔍 코드 하이라이트

### Win32 API 객체지향 래핑 예시
```cpp
// 기존 Win32 방식 (절차지향)
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch(msg) {
        case WM_LBUTTONDOWN:
            // 복잡한 좌표 처리...
            break;
    }
}

// CustomGUI 방식 (객체지향)  
class MyEvent {
    UINT msg_; WPARAM wParam_; LPARAM lParam_;
public:
    bool isLButtonDown() { return msg_ == WM_LBUTTONDOWN; }
    MyPoint getPos() { return MyPoint(LOWORD(lParam_), HIWORD(lParam_)); }
};
```

### 다형성을 활용한 도형 렌더링
```cpp
class Figure {
public:
    virtual void draw(HDC hdc) = 0;  // 순수 가상함수
};

class Rect : public Figure {
    void draw(HDC hdc) override { 
        Rectangle(hdc, left_, top_, right_, bottom_); 
    }
};

// 사용: 구체 타입에 관계없이 동일한 인터페이스
for (Figure* fig : figureList) {
    fig->draw(hdc);  // 실제 타입에 따라 알맞은 draw() 호출
}
```

---

*이 프로젝트는 객체지향프로그래밍 학습을 목적으로 순수 Win32 API만을 활용하여 GUI 프레임워크부터 애플리케이션까지 처음부터 구현한 학습용 프로젝트입니다.(2021)*