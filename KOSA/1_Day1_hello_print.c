#include <stdio.h>						// stdio.h 헤더 파일 포함
#include "Test_header.h"				// my_main() 함수와 실행 할 파일을 선택하는 헤더 호출

#if FILE_NUM == 1						// FILE_NUM을 참조하여 해당 파일이 맞다면 아래 코드 실행
int my_main(void) {						// my_main() 함수 호출
	printf_s("Hello, World! \n");		// 터미널에서 실행 시 Hello, World! 출력
	return 0;							// 0을 my_main 값으로 반환
}
#endif