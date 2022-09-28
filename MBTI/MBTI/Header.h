#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<Windows.h>

#define string_Question_I_E_1 "나는 처음 보는 사람에게 자신을 소개하는 것이 두렵지 않다."
#define string_Question_I_E_2 "내가 스트레스를 푸는 방법은 사람들을 만나는 것 이다."
#define string_Question_I_E_3 "대화를 시작하기보다 맞장구 치는걸 좋아한다."
#define string_Question_I_E_4 "술자리에서 노는것 보다 집에서 게임하는게 좋다."
#define string_Question_S_N_1 "업무를 하거나 과제를 할 때 계획을 먼저 세운다."
#define string_Question_S_N_2 "가끔 번뜩이는 아이디어가 생각나 메모를 하곤 한다."
#define string_Question_S_N_3 "가끔 비현실적인 망상을 하는 편이다."
#define string_Question_S_N_4 "나는 내성적인 성격이다."
#define string_Question_T_F_1 "상대방의 고민을 들어줄 때 원인을 찾기보다 공감을 해 주는 편이다."
#define string_Question_T_F_2 "어떤 이유에서건 상대방의 기분을 먼저 생각해야 한다."
#define string_Question_T_F_3 "다른 사람들이 나를 어떻게 생각하는지 지나치게 생각한다."
#define string_Question_T_F_4 "영화나 드라마가 뮤지컬이나 예술작품보다 더 많은 영감을 준다."
#define string_Question_J_P_1 "방 정리가 되어있지 않으면 일을 시작할 수 없다."
#define string_Question_J_P_2 "과제나 업무는 최대한 미루었다가 한꺼번에 하는 편 이다."
#define string_Question_J_P_3 "호기심은 나를 움직이는 원동력이다."
#define string_Question_J_P_4 "프리랜서나 회사원보다 더 나은 삶을 살고있다고 생각한다."

int TotalScore=0;