/*
자판기 프로그램을 만드시오.
자판기 프로그램은 동전 또는 지폐를 넣고 자판기에서 판매하는 다양한 상품을 구매하는 형식으로 만드시오.
판매하는 제품과 가격은 각 개인이 선택하되, 프로그램이 시작하면 각 판매 상품마다의 수량이 고정되어 있어야 한다.
특정 상품의 재고가 없는 경우 화면에 재고가 없음을 표시하시오.
자판기 판매 매출 정보를 확인 할 수 있어야 하며, 자판기를 초기화 하는 기능도 추가하시오.
구현의 예는 아래의 그림을 참고하시오.
*/

/*
1. 돈 투입 (100원 = a, 500원 = b, 1000원 = c) 투입할 때마다 현재 입력 금액 화면에 띄우기

2. 메뉴 선택 (1 콜라 2 사이다 3 코코팜 4 비타500 5 오렌지주스 6 커피 7 물)
  2-1. 넣은 돈보다 메뉴가 더 비싸면 돈 부족 멘트 화면에 띄우기
    2-1-1. 재고가 없으면 재고 부족 멘트 화면에 띄우기
      2-1-2. 아니면 넣은 금액에서 선택한 메뉴의 가격을 뺀 값을 화면에 띄우기

3. 동전 반환, 자판기 매출 보기, 자판기 매출 초기화 중 하나 고르기
  3-1. 동전 반환 시, 잔돈으로 나올 수 있는 최대 금액부터 출력. (예를 들어, 500원이 남았을 때, 100원 다섯 개가 아닌 500원 하나 출력)
    3-1-1. 자판기 계속 사용
      3-1-1-1. retu로 이동
    3-1-2. 프로그램 종료
  3-2. 자판기 매출 보기 (원래 수량에서 판 개수 뺀 값 출력, 그 값 X 가격 출력)
    3-2-1. 자판기 계속 사용
      3-2-1-1. retu로 이동
    3-2-2. 프로그램 종료
  3-3. 자판기 매출 초기화 loop으로 이동
  */

#define _CRT_SECURE_NO_WARNINGS //scanf() 오류를 방지하기 위한 상수 정의

#include <stdio.h>

int main(void)
{
	puts("19120068 강지연\n");

loop: //자판기 매출을 초기화했을 때 여기로 실행순서 이동

	int op = 0; //동전을 얼마나 넣을지에 대한 변수
	int menu = 0; //어떤 메뉴를 고를지에 대한 변수
	int change = 0; //동전 반환할 때 money를 저장할 변수
	int sell = 0; //동전 반환을 할지 자판기 매출을 볼지 자판기 매출 초기화를 할지에 대한 변수
	int coke = 9; //코카콜라 수량 고정
	int sprite = 5; //사이다 수량 고정
	int cocopam = 4; //코코팜 수량 고정
	int vita = 7; //비타500 수량 고정
	int orange = 8; //오렌지주스 수량 고정
	int coffee = 8; //커피 수량 고정
	int water = 6; //물 수량 고정

retu: //자판기를 초기화하지 않고 계속 쓰고 싶을 때 여기로 실행순서 이동

	int money = 0; //돈 저장

	puts("□□□□□□□□□□□□□□□□□□□□□□□□□");
	puts("▷▷▷▷▷▷　지연이의　음료　자판기　◁◁◁◁◁◁");
	puts("□□□□□□□□□□□□□□□□□□□□□□□□□");
	puts("□　１번 ： 코카콜라　　　　　(７００원)　　　　□");
	puts("□　２번 ： 사이다　　　　　　(７００원)　　　　□");
	puts("□　３번 ： 코코팜　　　　　　(１０００원)　　　□");
	puts("□　４번 ： 비타500 　　　　　(６００원)　　　　□");
	puts("□　５번 ： 오렌지쥬스　　　　(７００원)　　　　□");
	puts("□　６번 ： 커피　　　　　　　(５００원)　　　　□");
	puts("□　７번 ： 물　　　　　　　　(５００원)　　　　□");
	puts("□□□□□□□□□□□□□□□□□□□□□□□□□");
	puts("□　　　　　메뉴　키　(Ｋｅｙ)　안내　　　　　　□");
	puts("□〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓□");
	puts("□　ａ(Ａ) ： １００원짜리　동전　투입　　　　　□");
	puts("□　ｂ(Ｂ) ： ５００원짜리　동전　투입　　　　　□");
	puts("□　ｃ(Ｃ) ： １０００원짜리　지폐　투입　　　　□");
	puts("□　ｑ(Ｑ) ： 돈　다　투입했을　때　누르기　　　□");
	puts("□□□□□□□□□□□□□□□□□□□□□□□□□");
	puts("□　　　　　　　　돈을　넣으세요　　　　　　　　□");
	puts("□□□□□□□□□□□□□□□□□□□□□□□□□");

	do
	{
		printf("　▶");
		scanf("%s", &op); //동전을 얼마나 투입할 건지 입력

		switch (op) {
		case 'a':
			money += 100; //moeny에 100원 추가
			printf("　▶현재　투입된　금액：%d\n", money); //현재 money 출력
			break;

		case 'b':
			money += 500; //moeny에 500원 추가
			printf("　▶현재　투입된　금액：%d\n", money); //현재 money 출력
			break;

		case 'c':
			money += 1000;//moeny에 1000원 추가
			printf("　▶현재　투입된　금액：%d\n", money); //현재 money 출력
			break;

		case 'q':
			puts("　▶돈　투입　완료"); //q 누르면 입력 완료 안내 뜸
			break;

		default:
			op = 'q'; //op에 q 저장
		}
	} while (op != 'q'); //op가 q면 반복문 종료

	puts("□□□□□□□□□□□□□□□□□□□□□□□□□");
	puts("□　　　　　　　메뉴를　고르세요　　　　　　　　□");
	puts("□□□□□□□□□□□□□□□□□□□□□□□□□");
	printf("□　１번 ： 코카콜라　　　(７００원)　 　%d개　　□\n", coke);
	printf("□　２번 ： 사이다　　　　(７００원)　　 %d개　　□\n", sprite);
	printf("□　３번 ： 코코팜　　　　(１０００원) 　%d개　　□\n", cocopam);
	printf("□　４번 ： 비타500 　　　(６００원)　 　%d개　　□\n", vita);
	printf("□　５번 ： 오렌지쥬스　　(７００원)　 　%d개　　□\n", orange);
	printf("□　６번 ： 커피　　　　　(５００원)　 　%d개　　□\n", coffee);
	printf("□　７번 ： 물　　　　　　(５００원)　 　%d개　　□\n", water);
	puts("□　８번 ： 메뉴　다　고름　　　　　　　　　　　□");
	puts("□―――――――――――――――――――――――□");

	do
	{
		printf("　▶");
		scanf("%d", &menu); //메뉴 입력

		switch (menu) {
		case 1:
			if (money < 700) //만약 money가 코카콜라 값보다 작으면
			{
				puts("　▶돈이　부족합니다"); //돈 부족 멘트 출력
				break;
			}
			else
			{
				money -= 700; //money에서 코카콜라 값 뺀 값을 money에 저장
				coke -= 1; //coke에서 수량 하나 뺀 값을 coke에 저장
				if (coke < 1) //만약 콜라의 수가 1보다 작으면
				{
					printf("　▶재고 없음"); //재고 없음 출력
				}
				else
				{
					printf("　▶현재　남은　금액：%d\n", money); //코카콜라의 수가 1보다 많으면 남은 금액 출력
				}
				continue;
			}


		case 2:
			if (money < 700) //만약 money가 사이다 값보다 작으면
			{
				puts("　▶돈이　부족합니다"); //돈 부족 멘트 출력
				break;
			}
			else
			{
				money -= 700; //money에서 사이다 값 뺀 값을 money에 저장
				sprite -= 1; //sprite에서 수량 하나 뺀 값을 sprite에 저장
				if (sprite < 1) //만약 사이다의 수가 1보다 작으면
				{
					printf("　▶재고 없음"); //재고 없음 출력
				}
				else
				{
					printf("　▶현재　남은　금액：%d\n", money); //사이다의 수가 1보다 많으면 남은 금액 출력
				}
				continue;
			}

		case 3:
			if (money < 1000) //만약 money가 코코팜 값보다 작으면
			{
				puts("　▶돈이　부족합니다"); //돈 부족 멘트 출력
				break;
			}
			else
			{
				money -= 1000; //money에서 코코팜 값 뺀 값을 money에 저장
				cocopam -= 1; //cocopam에서 수량 하나 뺀 값을 cocopam에 저장
				if (cocopam < 1) //만약 코코팜의 수가 1보다 작으면
				{
					printf("　▶재고 없음"); //재고 없음 출력
				}
				else
				{
					printf("　▶현재　남은　금액：%d\n", money); //코코팜의 수가 1보다 많으면 남은 금액 출력
				}
				continue;
			}

		case 4:
			if (money < 600) //만약 money가 비타500 값보다 작으면
			{
				puts("　▶돈이　부족합니다"); //돈 부족 멘트 출력
				break;
			}
			else
			{
				money -= 600; //money에서 비타500 값 뺀 값을 money에 저장
				vita -= 1; //vita에서 수량 하나 뺀 값을 vita에 저장
				if (vita < 1) //만약 비타500의 수가 1보다 작으면
				{
					printf("　▶재고 없음"); //재고 없음 출력
				}
				else
				{
					printf("　▶현재　남은　금액：%d\n", money); //비타500의 수가 1보다 많으면 남은 금액 출력
				}
				continue;
			}

		case 5:
			if (money < 700) // 만약 money가 오렌지주스 값보다 작으면
			{
				puts("　▶돈이　부족합니다"); //돈 부족 멘트 출력
				break;
			}
			else
			{
				money -= 700; //money에서 오렌지주스 값 뺀 값을 money에 저장
				orange -= 1; //orange에서 수량 하나 뺀 값을 orange에 저장
				if (orange < 1) //만약 오렌지주스의 수가 1보다 작으면
				{
					printf("　▶재고 없음"); //재고 없음 출력
				}
				else
				{
					printf("　▶현재　남은　금액：%d\n", money); //오렌지주스의 수가 1보다 많으면 남은 금액 출력
				}
				continue;
			}

		case 6:
			if (money < 500) //만약 money가 커피 값보다 작으면
			{
				puts("　▶돈이　부족합니다"); //돈 부족 멘트 출력
				break;
			}
			else
			{
				money -= 500; //money에서 커피 값 뺀 값을 money에 저장
				coffee -= 1; //coffee에서 수량 하나 뺀 값을 coffee에 저장
				if (coffee < 1) //만약 커피의 수가 1보다 작으면
				{
					printf("　▶재고 없음"); //재고 없음 출력
				}
				else
				{
					printf("　▶현재　남은　금액：%d\n", money); //커피의 수가 1보다 많으면 남은 금액 출력
				}
				continue;
			}

		case 7:
			if (money < 500) //만약 money가 물 값보다 작으면
			{
				puts("　▶돈이　부족합니다"); //돈 부족 멘트 출력
				break;
			}
			else
			{
				money -= 500; //money에서 물 값 뺀 값을 money에 저장
				water -= 1; //water에서 수량 하나 뺀 값을 water에 저장
				if (water < 1) //만약 물의 수가 1보다 작으면
				{
					printf("　▶재고 없음"); //재고 없음 출력
				}
				else
				{
					printf("　▶현재　남은　금액：%d\n", money); //물의 수가 1보다 많으면 남은 금액 출력
				}
				continue;
			}

		case 8:
			puts("　▶메뉴　다　고름");
			break;

		default:
			menu = 8; //menu에 8 저장
		}
	} while (menu != 8); //menu가 8이면 반복문 종료

	puts("□□□□□□□□□□□□□□□□□□□□□□□□□");
	puts("□　ｓ(Ｓ) ： 동전　반환　　　　　　　　　　　　□");
	puts("□　ｙ(Ｙ) ： 자판기　판매　매출　보기　　　　　□");
	puts("□　ｗ(Ｗ) ： 자판기　판매　매출　초기화　　　　□");
	puts("□□□□□□□□□□□□□□□□□□□□□□□□□");

	printf("　▶");
	scanf("%s", &sell); //동전 반환, 자판기 매출 보기, 자판기 매출 초기화 중 고르기
	if (sell == 'y')
	{
		puts("　▶　　　　자판기　판매　매출　보기　　　　　◀　");
		puts("□―――――――――――――――――――――――□");
		printf("□　１번 ： 코카콜라　　　　%2d개　　　%4d원　　□\n", 9 - coke, (9 - coke) * 700);
		printf("□　２번 ： 사이다　　　　　%2d개　　　%4d원　　□\n", 5 - sprite, (5 - sprite) * 700);
		printf("□　３번 ： 코코팜　　　　　%2d개　　　%4d원　　□\n", 4 - cocopam, (4 - cocopam) * 1000);
		printf("□　４번 ： 비타500　　　　 %2d개　　　%4d원　　□\n", 7 - vita, (7 - vita) * 600);
		printf("□　５번 ： 오렌지쥬스　　　%2d개　　　%4d원　　□\n", 8 - orange, (8 - orange) * 700);
		printf("□　６번 ： 커피　　　　　　%2d개　　　%4d원　　□\n", 8 - coffee, (8 - coffee) * 500);
		printf("□　７번 ： 물　　　　　　　%2d개　　　%4d원　　□\n", 6 - water, (6 - water) * 500); //원래 수량에서 판 개수 뺀 값 출력, 그 값 X 가격 출력
		puts("□□□□□□□□□□□□□□□□□□□□□□□□□");
		puts("□　ｖ(Ｖ) ： 자판기　계속　사용　　　　　　　　□");
		puts("□　ｘ(Ｘ) ： 프로그램　종료　　　　　　　　　　□");

		scanf("%s", &sell);

		if (sell == 'v')
		{
			goto retu; //retu가 있는 위치로 실행순서를 이동한다
		}
		else if (sell == 'x')
		{
			return 0; //프로그램을 종료한다
		}

	}

	else if (sell == 's')
	{
		change = money; //change에 남은 돈(money) 저장

		puts("　▶　　　　　　　　동전　반환　　　　　　　　◀　");
		puts("□―――――――――――――――――――――――□");
		printf("　　１０００원짜리　지폐 ： %d\n", change / 1000); //1000원 반환 값
		printf("　　　５００원짜리　동전 ： %d\n", (change % 1000) / 500); //500원 반환 값
		printf("　　　１００원짜리　동전 ： %d\n", ((change % 1000) % 500) / 100); //100원 반환 값
		puts("□□□□□□□□□□□□□□□□□□□□□□□□□");
		puts("□　ｖ(Ｖ) ： 자판기　계속　사용　　　　　　　　□");
		puts("□　ｘ(Ｘ) ： 프로그램　종료　　　　　　　　　　□");

		scanf("%s", &sell);

		if (sell == 'v')
		{
			goto retu; //retu가 있는 위치로 실행순서를 이동한다
		}
		else if (sell == 'x')
		{
			return 0; //프로그램을 종료한다
		}
	}

	else if (sell == 'w')
	{
		puts("\n※　　　　　　시스템을　초기화했습니다　　　　　※");
		goto loop; //loop가 있는 위치로 실행순서를 이동한다
	}

	return 0;
}