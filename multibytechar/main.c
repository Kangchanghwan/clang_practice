#include <locale.h>
#include <stdio.h>
#include <wchar.h>
#include <sys/_types/_wchar_t.h>

int main(void) {
    // 로케일 설정 (UTF-8 환경에서 정상적으로 출력되도록)
    setlocale(LC_ALL, "");

    // 와이드 문자열 사용
    const wchar_t* str = L"안녕하세요!";
    wprintf(L"%ls\n", str);
}

