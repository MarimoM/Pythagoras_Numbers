// PitagoroSkaiciai.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	_declspec(align(16)) float skaiciai1[4];
	_declspec(align(16)) float skaiciai2[4];

	_declspec(align(16)) float rezultatai[4];

	_declspec(align(16)) float pirmas[4];
	_declspec(align(16)) float antras[4];

	int counter(0);

	for (int i = 1; i < 1000; i+=4) 
	{
		skaiciai2[0] = i;		//[1, 2, 3, 4]
		skaiciai2[1] = i+1;		
		skaiciai2[2] = i+2;		
		skaiciai2[3] = i+3;		
		
		for (int j = 1+i; j < 1000; j++)
		{
			skaiciai1[0] = j;	//[2, 3, 4, 5]
			skaiciai1[1] = j+1;
			skaiciai1[2] = j+2;
			skaiciai1[3] = j+3;

			_asm
			{
				movaps xmm0, skaiciai1 
				movaps xmm3, skaiciai1 //isimemame skaiciu
				mulps xmm0, xmm0 // sudauginam pirma eilute

				movaps xmm1, skaiciai2 
				movaps xmm4, skaiciai2 //saugom skaiciu
				mulps xmm1, xmm1 // sudauginam antra eilute

				addps xmm0, xmm1 // kvadratu suma
				movaps rezultatai, xmm0
				movaps xmm2, xmm0 //saugojam kvadratu suma

				sqrtps xmm0, xmm0 // saknis
				roundps xmm0, xmm0, 1
				mulps xmm0, xmm0 // kvadratas
				subps xmm2, xmm0

				movaps rezultatai, xmm2
				movaps pirmas, xmm3
				movaps antras, xmm4
			}
			for (int i = 0; i < 4; i++)
			{
				if (rezultatai[i] == 0) cout << pirmas[i] << " " << antras[i] << endl;
			}
		}
	}
}

