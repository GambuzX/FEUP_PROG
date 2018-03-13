#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <algorithm> 
#include <iomanip>
#include <list>
#include "Exercises1.h"
#include "Exercises2.h"
#include "Exercises3.h"
#include "Exercises4.h"

using namespace std;


void Exercises1::intro_exe()
{
	// variable declarations and initialization
	int operand1, operand2, result, answer;
	char operators[4] = { '+','-','*','/' };
	char operation; // why not 'operator' ...?
	int numCorrectAnswers = 0;
	int maxOperandValue;
	int numOperations;

	// initialize random number generator
	srand((unsigned int)time(NULL));

	cout << "Maximum operand value? "; cin >> maxOperandValue;
	cout << "Number of operations ? "; cin >> numOperations;

	// randomly generate operands and operator
	for (int i = 1; i <= numOperations; i++) {
		operand1 = rand() % maxOperandValue + 1;
		operand2 = rand() % maxOperandValue + 1;
		operation = operators[rand() % 4];
		// calculate the correct result 
		switch (operation) {
		case '+': result = operand1 + operand2;
			break;
		case '-': result = operand1 - operand2;
			break;
		case '*': result = operand1 * operand2;
			break;
		case '/':
			result = operand1 / operand2;
			break;
		}
		// ask the answer from the user
		cout << operand1 << " " << operation << " " << operand2 << " ? ";
		cin >> answer;
		// verify if the answer of the user is correct
		if (answer == result) {
			cout << "Correct answer. Congratulations\n";
			numCorrectAnswers++;
		}
		else
			cout << "Wrong answer ...\n";
	}

	// classify results 
	if (numCorrectAnswers <= (int)(0.3 * numOperations))
		cout << "VERY BAD ......\n";
	else
		if (numCorrectAnswers <= (int)(0.5 * numOperations))
			cout << "POOR...\n";
		else
			if (numCorrectAnswers <= (int)(0.7 * numOperations))
				cout << "FAIR\n";
			else
				if (numCorrectAnswers <= (int)(0.9 * numOperations))
					cout << "GOOD !\n";
				else
					cout << "EXCELLENT !!!\n";
}

void Exercises1::exe1_1()
{
	char letra;

	cout << "Letra?  ";
	cin >> letra;
	cout << (int)letra << endl;
}

void Exercises1::exe1_2()
{
	float a, b, c; //inicializar variáveis
	float media;

	cout << "A ? "; cin >> a;
	cout << "B ? "; cin >> b;
	cout << "C ? "; cin >> c;

	media = (a + b + c) / (float)3;

	cout << "media   = " << fixed << setprecision(3) << media << endl;
	cout << "A-media = " << fixed << setprecision(3) << a - media << endl;
	cout << "B-media = " << fixed << setprecision(3) << b - media << endl;
	cout << "C-media = " << fixed << setprecision(3) << c - media << endl;
}

void Exercises1::exe1_3()
{
	double M, p, r; //initialize variables
	const double pi = 3.1415; //pi

	cout << "Sphere's material mass (Kg/m3) = "; cin >> p;
	cout << "Radius (m) = "; cin >> r;

	M = 4 / 3 * p * pi * pow(r, 3);

	cout << "Sphere's mass = " << M << " Kg" << endl;
}

void Exercises1::exe1_4()
{
	float x, y, a, b, c, d, e, f; //initialize variables

	cout << "a = "; cin >> a;//
	cout << "b = "; cin >> b;//
	cout << "c = "; cin >> c;//  Read a ~ f values
	cout << "d = "; cin >> d;//
	cout << "e = "; cin >> e;//
	cout << "f = "; cin >> f;//

	if (a*e - b * d != 0) {

		x = (c*e - b * f) / (a*e - b * d);
		y = (a*f - c * d) / (a*e - b * d);

		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
	}

}

void Exercises1::exe1_5()
{

	int hoursT1, minutesT1, secondsT1;
	int hoursT2, minutesT2, secondsT2; //initialize variables
	int days = 0, hours = 0, minutes = 0, seconds = 0;

	cout << "Tempo 1 (horas minutos segundos) ? "; cin >> hoursT1 >> minutesT1 >> secondsT1;  //Read Time1
	cout << "Tempo 2 (horas minutos segundos) ? "; cin >> hoursT2 >> minutesT2 >> secondsT2;//Read Time2

	if (secondsT1 + secondsT2 >= 60) {  //Math for seconds
		minutes += 1;
		seconds = secondsT1 + secondsT2 - 60;
	}
	else {
		seconds = secondsT1 + secondsT2;
	}

	if (minutes + minutesT1 + minutesT2 >= 60) { //Math for minutes
		hours += 1;
		minutes += (minutesT1 + minutesT2 - 60);
	}
	else {
		minutes += (minutesT1 + minutesT2);
	}

	if (hours + hoursT1 + hoursT2 >= 24) { //Math for hours
		days = 1;
		hours += (hoursT1 + hoursT2 - 24);
	}
	else {
		hours += (hoursT1 + hoursT2);
	}

	if (days == 0) {
		cout << "Soma dos tempos: " << hours << " horas, " << minutes << " minutos e " << seconds << " segundos" << endl;
	}
	else {
		cout << "Soma dos tempos: " << days << " dia, " << hours << " horas, " << minutes << " minutos e " << seconds << " segundos" << endl;
	}
}

float Exercises1::exe1_6()
{
	float x1, y1, x2, y2, x3, y3; //Coordenadas dos vertices
	float a, b, c, s, area;

	cout << "Lado 1 (x,y) = "; cin >> x1 >> y1;
	cout << "Lado 2 (x,y) = "; cin >> x2 >> y2; //Recebe os valores das coordenadas
	cout << "Lado 3 (x,y) = "; cin >> x3 >> y3;

	a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2)); //Calcula os valores dos lados
	c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));

	s = (a + b + c) / 2; // Calcula o semiperimetro

	area = sqrt(s * (s - a) * (s - b) * (s - c)); //Calcula a area

	cout << "Area = " << area << endl; //Apresenta a area
	return area;//Devolve a area
}

void Exercises2::exe2_2_a()
{
	float a, b, c;

	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;
	cout << "c = "; cin >> c;

	cout << "max = " << max(a, max(b, c)) << endl;
	cout << "min = " << min(a, min(b, c)) << endl;
}

void Exercises2::exe2_2_b()
{
	float a, b, c;

	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;
	cout << "c = "; cin >> c;

	if (max(a, max(b, c)) == a) { //if the maximum is a
		cout << a << " >= " << max(b, c) << " >= " << min(b, c) << endl;
	}
	else if (max(a, max(b, c)) == b) { //if the maximum is b 
		cout << b << " >= " << max(a, c) << " >= " << min(a, c) << endl;
	}
	else {//if the maximum is c
		cout << c << " >= " << max(b, a) << " >= " << min(b, a) << endl;
	}
}

void Exercises2::exe2_2_c()
{
	double a, b, c;

	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;
	cout << "c = "; cin >> c;

	if (max(a, max(b, c)) == a) { //if the maximum is a

		if (b + c > a) { //if the sum of the 2 smaller sides is larger than the larger side
			cout << "Possible" << endl;
		}
		else {
			cout << "Not possible" << endl;
		}
	}
	else if (max(a, max(b, c)) == b) {//if the maximum is b
		if (a + c > b) { //if the sum of the 2 smaller sides is larger than the larger side
			cout << "Possible" << endl;
		}
		else {
			cout << "Not possible" << endl;
		}
	}
	else { //if the maximum is c
		if (b + a > c) { //if the sum of the 2 smaller sides is larger than the larger side
			cout << "Possible" << endl;
		}
		else {
			cout << "Not possible" << endl;
		}
	}
}

void Exercises2::exe2_3()
{
	double a, b, result;
	char op;

	cin >> a >> op >> b;

	switch (op) {
	case '+':
		result = a + b;
		break;
	case '-':
		result = a - b;
		break;
	case '*':
		result = a * b;
		break;
	case '/':
		result = a / b;
		break;
	}

	cout << " = " << result << endl;
}

void Exercises2::exe2_4()
{
	double weight, cost;

	cout << "Peso da mercadoria (gramas) = ";
	cin >> weight;

	if (weight <= 0) {
		cout << "Free shipping! :D " << endl;
		return;
	}

	if (weight < 500) {
		cost = 5;
	}
	else if (weight <= 1000) {
		double dif = weight - 500; //Peso que excede os 500g
		cost = 5 + 1.5 * (dif / 100); // Calculo do custo
	}
	else {
		double dif = weight - 1000;//Peso que excede os 1000g
		cost = 12.5 + 5 * (dif / 250);// Calculo do custo
	}

	cout << "Custo (euros) = " << cost << endl;
}

void Exercises2::exe2_5()
{
	int a, b, c;
	double sign;
	bool dif = false, eq = false, complx = false;

	cout << "Introduza os coeficientes (a b c): ";
	cin >> a >> b >> c;

	sign = pow(b, 2) - 4 * a * c;

	if (sign > 0)
		dif = true;
	else if (sign == 0)
		eq = true;
	else if (sign < 0)
		complx = true;

	if (dif) {
		double root1, root2;

		root1 = ((-b + sqrt(sign)) / (2 * a));
		root2 = ((-b - sqrt(sign)) / (2 * a));

		cout << "A equacao tem 2 raizes reais: " << fixed << setprecision(3) << root1;
		cout << " e " << fixed << setprecision(3) << root2 << endl;
	}
	else if (eq) {
		double root;
		root = -b / (2 * a);

		cout << "A equacao tem 2 raizes reais iguais: " << fixed << setprecision(3) << root << endl;
	}
	else if (complx) {
		double realP, imagP;
		realP = (-b) / (2 * a);
		imagP = sqrt(-sign) / (2 * a);

		cout << "A equacao tem 2 raizes complexas conjugadas: ";
		cout << fixed << setprecision(3) << realP << "+" << imagP << "i";
		cout << " e " << fixed << setprecision(3) << realP << "-" << imagP << "i" << endl;
	}



}

void Exercises2::exe2_6_a()
{ //Determines if a number is prime or not
	int number;
	float prime = true;
	float valid = true;

	cout << "Number: "; //Asks for the number to test if it is prime
	cin >> number;

	switch (number) {
	case 1: //if number is 1
		break;
	case 2: //if number is 2
		break;
	default:
		if (number > 0) //if the number is greater than 0
		{
			for (int i = 2; i < sqrt(number); i++) {
				if (number % i == 0)
					prime = false;
				else
					continue;
			}
		}
		else //if the number is 0 or negative
		{
			cout << "Not a valid number!\n";
			valid = false;
		}
	}

	if (prime && valid) {
		cout << number << " is prime.\n";
	}
	else if (!prime && valid) {
		cout << number << " is not prime.\n";
	}
}

bool Exercises2::isPrime(int number)  //Determines if a number is prime or not
{
	float prime = true;

	switch (number) {
	case 1: //if number is 1
		return true;
	case 2: //if number is 2
		return true;
	default:
		if (number > 0) //if the number is greater than 0
		{
			for (int i = 2; i <= sqrt(number); i++) {
				if (number % i == 0)
					prime = false;
				else
					continue;
			}
		}
		else //if the number is 0 or negative
		{
			prime = false;
		}
	}

	if (prime)
		return true;
	else
		return false;
}

void Exercises2::exe2_6_b()
{
	int primeCount = 0;
	int number = 1;

	while (primeCount <= 100) {
		if (isPrime(number)) {
			cout << number << endl;
			primeCount += 1;
		}
		number += 1;
	}

	cout << endl;
}

void Exercises2::exe2_6_c()
{
	for (int i = 1; i < 10000; i++) {
		if (isPrime(i))
			cout << i << endl;
	}
	cout << endl;
}

void Exercises2::exe2_7_a()
{
	cout << "ang     " << "sen       " << "cos       " << "tan   " << endl;

	long double pi = acos(-1);
	for (int i = 0; i <= 90; i += 15) {
		double angleRad = i * pi / 180;
		double seno = sin(angleRad) * 1.000000;
		double cosseno = cos(angleRad) * 1.000000;

		cout << setw(3) << i;
		cout << fixed << setprecision(6) << setw(10) << seno;
		cout << fixed << setprecision(6) << setw(10) << cosseno;

		if (i % 90 == 0 && !(i % 180 == 0)) { // if the angle is equal to 90, 270, 450 (...), with an infinite tangent
			cout << setw(9) << "infinito" << endl;
		}
		else {
			cout << setw(9) << tan(angleRad) * 1.000000 << endl;
		}
	}
}

void Exercises2::exe2_7_b()
{

	float lowerLimit, upperLimit, step; // Variables for user input

	cout << "Lower limit = "; cin >> lowerLimit;
	cout << "Upper limit = "; cin >> upperLimit;
	cout << "Value increment = "; cin >> step;
	cout << endl << endl; // Space for better looks

	cout << " ang     " << "sen       " << "cos       " << "tan   " << endl;

	long double pi = acos(-1);
	for (float i = lowerLimit; i <= upperLimit; i += step) {
		double angleRad = i * pi / 180;
		double seno = sin(angleRad) * 1.000000;
		double cosseno = cos(angleRad) * 1.000000;

		cout << fixed << setprecision(1) << setw(4) << i;
		cout << fixed << setprecision(6) << setw(10) << seno;
		cout << fixed << setprecision(6) << setw(10) << cosseno;

		if ((int)i % 90 == 0 && !((int)i % 180 == 0)) { // if the angle is equal to 90, 270, 450 (...), with an infinite tangent
			cout << setw(10) << "infinito" << endl;
		}
		else { // if not equal to any of those specific angles
			cout << setw(10) << tan(angleRad) * 1.000000 << endl;
		}
	}
}

void Exercises2::exe2_9_a()
{
	list<int> numbers = list<int>();
	int a; //variavel para guardar inputs

	cout << "Lista de numeros: ";

	do //Adiciona valores à lista enquanto o valor for diferente de 0
	{
		cin >> a; //recebe valor
		numbers.push_back(a);
	} while (a != 0);

	numbers.pop_back(); //remove o 0 no fim

	int soma = 0, min, max, listSize;
	double media;

	min = numbers.front(); //atribui o valor inicial a min
	max = numbers.front();//atribui o valor inicial a max

	listSize = numbers.size(); //guarda o tamanho inicial da lista (antes de ser modificada)

	for (int i = 0; i < listSize; i++) {
		int currentNumber = numbers.front(); //identifica o primeiro elemento
		soma += currentNumber;//soma o primeiro elemento

		if (currentNumber > max) //verifica se o numero é superior ao maximo
			max = currentNumber;
		if (currentNumber < min)//verifica se o numero é superior ao minimo
			min = currentNumber;

		numbers.pop_front(); //remove o primeiro elemento
	}

	media = (double)soma / listSize; //calculo da media

	cout << "Soma = " << soma << endl;
	cout << "Menor valor = " << min << endl; // Outputs
	cout << "Maior valor = " << max << endl;
	cout << "Media = " << media << endl;
	cout << "Comprimento da sequencia = " << listSize << endl;

	return;
}

void Exercises2::exe2_9_b()
{
	int numElem, soma = 0, min, max, comp;
	double media;
	bool firstLoop = true;

	cout << "Numero de elementos: ";
	cin >> numElem;

	comp = numElem;
	cout << "Introduza os elementos: ";

	while (numElem > 0) {
		int number;
		cin >> number;

		soma += number;

		if (firstLoop) {
			min = number;
			max = number;
			firstLoop = false;
		}
		else if (number > max)
			max = number;
		else if (number < min)
			min = number;

		numElem--;
	}

	media = (double)soma / comp;

	cout << "Soma = " << soma << endl;
	cout << "Menor valor = " << min << endl; // Outputs
	cout << "Maior valor = " << max << endl;
	cout << "Media = " << media << endl;
	cout << "Comprimento da sequencia = " << comp << endl;

	return;
}

void Exercises2::exe2_9_c()
{
	int numElem = 0, soma = 0, min, max;
	double media;
	bool firstLoop = true;

	while (!cin.eof()) {
		int number;
		cin >> number;

		if (cin.fail()) {
			if (cin.eof())
				break;
			else {
				cin.clear();
				cin.ignore(10000, '\n');
				continue;
			}
		}

		soma += number;

		if (firstLoop) {
			min = number;
			max = number;
			firstLoop = false;
		}
		else if (number > max)
			max = number;
		else if (number < min)
			min = number;
		numElem++;
	}

	media = (double)soma / numElem;

	cout << "Soma = " << soma << endl;
	cout << "Menor valor = " << min << endl; // Outputs
	cout << "Maior valor = " << max << endl;
	cout << "Media = " << media << endl;
	cout << "Comprimento da sequencia = " << numElem << endl;

	return;
}

void Exercises2::exe2_10_a()
{
	int number, firstDigit, lastDigit;
	bool capicua = false;

	cout << "Numero de 3 digitos: ";
	cin >> number;

	if ((int)number / 100 == 0 || (int)number / 100 > 9) {
		cout << number << " nao tem 3 digitos!\n";
		return;
	}

	firstDigit = number % 10;
	lastDigit = number / 100;

	if (firstDigit == lastDigit)
		capicua = true;

	if (capicua)
		cout << number << " e uma capicua!\n";
	else
		cout << number << " nao e uma capicua!\n";

	return;
}

void Exercises2::exe2_10_b()
{
	int number;
	bool capicua = true;

	cout << "Numero? ";
	cin >> number;

	string input = to_string(number); //converte o numero em string
	int inputSize = input.length(); //guarda o valor do tamanho da string
	for (int i = 0; i < inputSize / 2; i++) {
		if (input[i] == input[inputSize - 1 - i]) { //se o digito na posicao i for igual ao digito na posicao (tamanho - i)
			continue;
		}
		else {
			capicua = false;
			break;
		}
	}

	if (capicua) {
		cout << input << " e uma capicua!\n";
	}
	else if (!capicua) {
		cout << input << " nao e uma capicua!\n";
	}

	return;
}

double Exercises2::exe2_11_a() //serie que devolve o valor de pi
{
	int n;
	cout << "n? ";
	cin >> n;

	int denominador = 1;
	double total = 0L;
	bool soma = true;

	for (int i = 1; i <= n; i++) {
		double valor = (double) 4.0 / denominador; //calcula o valor a ser somado
		denominador += 2; //incrementa o denominador para a proxima operacao		
		if (soma) {
			total += valor; //adiciona o valor ao acumulador
			soma = false; //coloca soma a falso para que a proxima operacao seja subtracao
		}
		else {
			total -= valor;
			soma = true;
		}
	}
	return total;
}

double Exercises2::exe2_11_b() //serie que devolve o valor do numero de Neper
{
	int n;
	cout << "n? ";
	cin >> n;

	int fatorial = 1;
	double total = 1L;

	for (int i = 2; i <= n; i++) {
		double valor = (double)1 / fatorial; //calcula o valor a ser somado
		fatorial = fatorial * (fatorial + 1); //incrementa o fatorial para a proxima operacao

		total += valor;
	}
	return total;
}

double Exercises2::exe2_11_c() //serie que devolve o valor de pi
{
	int n, x;
	cout << "n? ";
	cin >> n;
	cout << "x? ";
	cin >> x;

	int fatorial = 1;
	int expoente = 1;
	double total = 1L;
	bool soma = false; //comeca a subtrair

	for (int i = 2; i <= n; i++) { //comeca no segundo termo
		double valor = (double)pow(x, expoente) / fatorial; //calcula o valor a ser somado
		fatorial = fatorial * (fatorial + 1); //incrementa o fatorial para a proxima operacao	
		expoente++; //incrementa o expoente

		if (soma) {
			total += valor; //adiciona o valor ao acumulador
			soma = false; //coloca soma a falso para que a proxima operacao seja subtracao
		}
		else {
			total -= valor;
			soma = true;
		}
	}
	return total;
}

void Exercises2::exe2_13()
{
	list<int> numbers = list<int>();
	int number, fixedNumber;

	cout << "Numero a decompor em fatores? ";
	cin >> number;
	fixedNumber = number;

	if (number == 1 || number == 0) {
		cout << number << " = " << number;
	}
	else { //if the number is bigger than 1
		while (number != 1) { // se no momento nao for 1 (vai sendo atualizado)
			for (int i = 2; i <= number; i++) { //procura o menor divisor
				if ((double)(number % i) == 0) { // se o valor for divisor do numero
					number = number / i; // atualiza o valor para a proxima iteracao
					numbers.push_back(i); // coloca no fim da lista o valor
					break;
				}
				else // se nao for divisor continua a procurar divisores
					continue;
			}
		}
	}
	cout << fixedNumber << " = ";

	int fixedSize = numbers.size();
	for (int i = 0; i < fixedSize; i++) {
		cout << numbers.front();
		numbers.pop_front();
		if ((i + 1) < fixedSize) //escrever um 'x' se nao for o ultimo numero
			cout << "x";
		else
			cout << endl;
	}

	return;
}

void Exercises2::exe2_14_a()
{
	int numero, nMaxIter;
	double delta;
	cout << "Numero = "; cin >> numero;
	cout << "Numero maximo de iteracoes = "; cin >> nMaxIter;
	cout << "Valor de delta = "; cin >> delta;

	int nIter = 0;
	double rq = 1, rqn, dif;

	do {
		rqn = (double)(rq + numero / rq) / 2; //calcula rqn
		rq = rqn; //atualiza rq
		dif = (double)numero - pow(rqn, 2); //calcula dif
		nIter++; //incrementa iteracoes
	} while (nIter <= nMaxIter && abs(dif) >= delta);

	cout << "Raiz quadrada ~= " << rq << endl;

	return;

}

void Exercises2::exe2_14_b()
{
	int numero, nMaxIter;
	double delta;
	cout << "Numero = "; cin >> numero;
	cout << "Numero maximo de iteracoes = "; cin >> nMaxIter;
	cout << "Valor de delta = "; cin >> delta;

	int nIter = 0;
	double rq = 1, rqn, dif;

	do {
		rqn = (double)(rq + numero / rq) / 2; //calcula rqn
		rq = rqn; //atualiza rq
		dif = (double)numero - pow(rqn, 2); //calcula dif
		nIter++; //incrementa iteracoes
	} while (nIter <= nMaxIter && abs(dif) >= delta);

	string input = to_string(delta);
	int casasDecimais = input.length() - 2; //tamanho da string menos o 0 e o ponto

	cout << "Raiz quadrada ~= " << rq << endl;

	return;

}

int Exercises3::exe3_8(int m, int n)
{ // Algoritmo de euclides

	if (m % n == 0) { // Se n for divisor de m
		return n;
	}
	else { // Se n nao for divisor, caso recursivo
		exe3_8(n, m % n);
	}
}

double Exercises3::distance(double x1, double y1, double x2, double y2)
{
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

double Exercises3::area(double x1, double y1, double x2, double y2, double x3, double y3)
{
	double a,b,c,s,total;
	a = distance(x1, y1, x2, y2);
	b = distance(x2, y2, x3, y3);
	c = distance(x3, y3, x1, y1);
	s = (a + b + c) / 2;
	total = sqrt(s*(s - a)*(s - b)*(s - c));
	return total;
}

double Exercises3::round(double x, unsigned n)
{
	double y;
	double mult = pow(10,n);

	y = floor(x * mult + 0.5) / mult;

	return y;
}

void Exercises3::testRound()
{
	double x;
	unsigned n;

	cout << "x? "; cin >> x;
	cout << "n? "; cin >> n;

	cout << "Rounded value = " << fixed << setprecision (n) << round(x, n);
}

bool Exercises3::readFracc(int & numerator, int & denominator)
{
	char bar; // Char to hold the bar between the numbers, so as not to trigger the error flag
	cin >> numerator >> bar >> denominator; // Keeps the input values

	if (cin && bar == '/')
		return true;
	else {
		numerator = 0;
		denominator = 0;
		return false;
	}
}

void Exercises3::writeFracc(int numerator, int denominator)
{
	cout << numerator << '/' << denominator << endl;
}

int Exercises3::gcd(int a, int b)
{
	int q = 0;
	int r = 0;

	/*   b = qa + r   */
	do {

		q = b / a;
		r = b % a;

		b = a;
		if (r) a = r;

	} while (r != 0);

	return a;

}

void Exercises3::reduceFracc(int & numerator, int & denominator)
{
	int mdc = gcd(numerator, denominator);
	numerator = numerator / mdc;
	denominator = denominator / mdc;
}

double Exercises3::addFracc(int & numerator1, int & denominator1, int  numerator2, int  denominator2)
{
	int tempNumerator2 = numerator2 * denominator1;
	numerator1 = numerator1 * denominator2 + tempNumerator2;
	denominator1 = denominator1 * denominator2;
	reduceFracc(numerator1, denominator1);
	return (double) numerator1 / denominator1;

}

double Exercises3::subFracc(int & numerator1, int & denominator1, int  numerator2, int  denominator2)
{
	int tempNumerator2 = numerator2 * denominator1;
	numerator1 = numerator1 * denominator2 - tempNumerator2;
	denominator1 = denominator1 * denominator2;
	reduceFracc(numerator1, denominator1);
	return (double)numerator1 / denominator1;
}

double Exercises3::multFracc(int & numerator1, int & denominator1, int  numerator2, int  denominator2)
{
	numerator1 = numerator1 * numerator2;
	denominator1 = denominator1 * denominator2;
	reduceFracc(numerator1, denominator1);
	return (double)numerator1 / denominator1;
}

double Exercises3::divFracc(int & numerator1, int & denominator1, int  numerator2, int  denominator2)
{
	numerator1 = numerator1 * denominator2;
	denominator1 = denominator1 * numerator2;
	reduceFracc(numerator1, denominator1);
	return (double)numerator1 / denominator1;
}

bool Exercises3::testFraccOps(int numerator1, int denominator1, int numerator2, int denominator2)
{
	// Function for testing the previously defined functions
	// Compares the results from those functions with the direct calculation of the operations

	const double delta = 0.000001; //error associated

	double frac1 = (double) numerator1 / denominator1;
	double frac2 = (double) numerator2 / denominator2;
	
	double sum = frac1 + frac2; cout << sum << endl;
	double dif = frac1 - frac2; cout << dif << endl;
	double mult = frac1 * frac2; cout << mult << endl;
	double div = frac1 / frac2; cout << div << endl;

	int a, b;
	a = numerator1;
	b = denominator1;
	double sumFunct = addFracc(a, b, numerator2, denominator2);
	cout << sumFunct << endl;

	a = numerator1;
	b = denominator1;
	double difFunct = subFracc(a, b, numerator2, denominator2);
	cout << difFunct << endl;

	a = numerator1;
	b = denominator1;
	double multFunct = multFracc(a, b, numerator2, denominator2);
	cout << multFunct << endl;

	a = numerator1;
	b = denominator1;
	double divFunct = divFracc(a, b, numerator2, denominator2);
	cout << divFunct << endl;

	return (abs(sum - sumFunct) < delta) && (abs(dif - difFunct) < delta) && (abs(mult - multFunct) < delta) && (abs(div - divFunct) < delta);
}

bool Exercises3::isLeapYear(int year)
{
	// Returns a boolean representing whether or not the year is a Leap Year
	bool bLeapYear;

	if (year % 400 == 0) //divisivel por 400
		bLeapYear = true;
	else if (year % 100 != 0 && year % 4 == 0) //divisivel por 4, mas não por 100
		bLeapYear = true;
	else
		bLeapYear = false;

	return bLeapYear;
}

int Exercises3::daysInMonthOfYear(int month, int year)
{
	//returns the number of days of the specified month in the specified year
	bool leapYear = isLeapYear(year);

	switch (month) {
	case 1:	return 31;
	case 2:	if (leapYear)
				return 29;
			else
				return 28;
	case 3: return 31;
	case 4: return 30;
	case 5: return 31;
	case 6: return 30;
	case 7: return 31;
	case 8: return 31;
	case 9: return 30;
	case 10: return 31;
	case 11: return 30;
	case 12: return 31;

	default:
		return 0;
	}
}

int Exercises3::weekDay(int day, int month, int year)
{
	bool leapYear = isLeapYear(year);

	int ds, s, a, c; // s = 2 first digits of year; a = 2 last digits of year; c = month code

	s = year / 100;
	a = year % 100;

	if (leapYear) { //sets the month code depending on the year, if it is a leap year or not
		switch (month) {
		case 1: c = 6; break;
		case 2: c = 2; break;
		case 3: c = 3; break;
		case 4: c = 6; break;
		case 5: c = 1; break;
		case 6: c = 4; break;
		case 7: c = 6; break;
		case 8: c = 2; break;
		case 9: c = 5; break;
		case 10: c = 0; break;
		case 11: c = 3; break;
		case 12: c = 5; break;
		}
	}
	else {
		switch (month) {
		case 1: c = 0; break;
		case 2: c = 3; break;
		case 3: c = 3; break;
		case 4: c = 6; break;
		case 5: c = 1; break;
		case 6: c = 4; break;
		case 7: c = 6; break;
		case 8: c = 2; break;
		case 9: c = 5; break;
		case 10: c = 0; break;
		case 11: c = 3; break;
		case 12: c = 5; break;
		}
	}

	ds = ((5*a/4) + c + day - 2*(s%4) + 7) % 7; // Formula de calculo do dia da semana de Sohael Babwani

	return ds;
}

void Exercises3::writeWeekDay(int day, int month, int year)
{
	day = weekDay(day, month, year);

	switch (day) {
	case 0:
		cout << "Sabado";
		break;
	case 1:
		cout << "Domingo";
		break;
	case 2:
		cout << "Segunda-feira";
		break;
	case 3:
		cout << "Terca-feira";
		break;
	case 4:
		cout << "Quarta-feira";
		break;
	case 5:
		cout << "Quinta-feira";
		break;
	case 6:
		cout << "Sexta-feira";
		break;	
	default:
		break;
	}

	return;
}

void Exercises3::writeMonth(int month)
{
	switch (month) {
	case 1:
		cout << "Janeiro";
		break;
	case 2:
		cout << "Fevereiro";
		break;
	case 3:
		cout << "Marco";
		break;
	case 4:
		cout << "Abril";
		break;
	case 5:
		cout << "Maio";
		break;
	case 6:
		cout << "Junho";
		break;
	case 7:
		cout << "Julho";
		break;
	case 8:
		cout << "Agosto";
		break;
	case 9:
		cout << "Setembro";
		break;
	case 10:
		cout << "Outubro";
		break;
	case 11:
		cout << "Novembro";
		break;
	case 12:
		cout << "Dezembro";
		break;
	}
	return;
}

void Exercises3::writeTimetableMonthInYear(int month, int year)
{
	int totalDays = daysInMonthOfYear(month, year);
	int dayOfWeek = weekDay(1, month, year);

	writeMonth(month); cout << "/" << year << endl;  //Timetable headers
	cout << "Dom";
	cout << fixed << setw(5) << "Seg";
	cout << fixed << setw(5) << "Ter";
	cout << fixed << setw(5) << "Qua";
	cout << fixed << setw(5) << "Qui";
	cout << fixed << setw(5) << "Sex";
	cout << fixed << setw(5) << "Sab" << endl;

	int tableColumn;
	switch (dayOfWeek) { //Write spaces for the first day
	case 0:
		cout << fixed << setw(3) << " ";
		cout << fixed << setw(5) << " ";
		cout << fixed << setw(5) << " ";
		cout << fixed << setw(5) << " ";
		cout << fixed << setw(5) << " ";
		cout << fixed << setw(5) << " ";
		tableColumn = 7;
		break;
	case 1:
		tableColumn = 1;
		break;
	case 2:
		cout << fixed << setw(3) << " ";
		tableColumn = 2;
		break;
	case 3:
		cout << fixed << setw(3) << " ";
		cout << fixed << setw(5) << " ";
		tableColumn = 3;
		break;
	case 4:
		cout << fixed << setw(3) << " ";
		cout << fixed << setw(5) << " ";
		cout << fixed << setw(5) << " ";
		tableColumn = 4;
		break;
	case 5:
		cout << fixed << setw(3) << " ";
		cout << fixed << setw(5) << " ";
		cout << fixed << setw(5) << " ";
		cout << fixed << setw(5) << " ";
		tableColumn = 5;
		break;
	case 6:
		cout << fixed << setw(3) << " ";
		cout << fixed << setw(5) << " ";
		cout << fixed << setw(5) << " ";
		cout << fixed << setw(5) << " ";
		cout << fixed << setw(5) << " ";
		tableColumn = 6;
		break;
	default:
		break;
	}

	for (int day = 1; day <= totalDays; day++) {
		if (tableColumn == 1) //se na primeira coluna
			cout << fixed << setw(3) << day;
		else //se nao na primeira coluna
			cout << fixed << setw(5) << day;

		tableColumn++; //incrementa sempre o valor da coluna
		if (tableColumn > 7) { //se a coluna for a ultima, fazer endl
			cout << endl;
			tableColumn = 1;
		}
	}
	
	cout << endl;
	return;
}

void Exercises3::writeTimetableYear(int year)
{
	for (int month = 1; month <= 12; month++) {
		writeTimetableMonthInYear(month, year);
		cout << endl;
	}
	return;
}

long int Exercises3::factorial_ite(int n)
{
	long int total = 1;

	for (int i = n; i >= 1; i--) {
		total = total * i;
	}

	return total;
}

int Exercises3::recursiveEuclidesAlgorithm(int m, int n)
{
	if (m % n == 0)
		return n;
	else
		recursiveEuclidesAlgorithm(n, m%n);
	return 1;
}

bool Exercises3::testEuclidesAlgorithm(int m, int n)
{
	int gdc = recursiveEuclidesAlgorithm(m, n);
	return (m % gdc == 0) && (n % gdc == 0) && (recursiveEuclidesAlgorithm(m, gdc) % n != 0) && (recursiveEuclidesAlgorithm(n, gdc) % m != 0);
}

bool Exercises4::isHydroxide(char compound[])
{
	int length = strlen(compound);
	return (compound[length - 2] == 'O') && (compound[length - 1] == 'H');
}

void Exercises4::testIsHydroxide()
{
	char koh[] = "KOH";
	cout << "Is KOH an Hydroxide? " << isHydroxide(koh) << endl;

	char h202[] = "H2O2";
	cout << "Is H2O2 an Hydroxide? " << isHydroxide(h202) << endl;

	char nacl[] = "NaCl";
	cout << "Is NaCl an Hydroxide? " << isHydroxide(nacl) << endl;

	char naoh[] = "NaOH";
	cout << "Is NaOH an Hydroxide? " << isHydroxide(naoh) << endl;

	char c9h804[] = "C9H8O4";
	cout << "Is C9H8O4 an Hydroxide? " << isHydroxide(c9h804) << endl;

	char mgoh[] = "MgOH";
	cout << "Is MgOH an Hydroxide? " << isHydroxide(mgoh) << endl;

	return;
}

bool Exercises4::sequenceSearch(string s, int nc, char c)
{
	bool hasSequence = false;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == c) {
			for (int j = 0; j < nc; j++) {
				if (s[i + j] == c) {
					if (j + 1 == nc)
						hasSequence = true;
					continue;
				}
				else
					break;
			}
		}
		else
			continue;
	}

	return hasSequence;
}

void Exercises4::decompose(string compound)
{
	cout << "O composto quimico " << compound << " tem como elementos ";
	int length = compound.length();
	

	for (int i = 0; i < length; i++) {
		if (isupper(compound[i]))
			if (!islower(compound[i + 1]))
				cout << compound[i] << " ";
			else
				cout << compound[i] << compound[i + 1] << " ";
		else
			continue;
	}
	cout << endl;
	return;
}

void Exercises4::testDecompose()
{
	decompose("H2O");
	decompose("KOH");
	decompose("H2O2");
	decompose("NaCl");
	decompose("NaOH");
	decompose("C9H8O4");
	decompose("MgOH");
	return;
}

string Exercises4::normalizeName(string name)
{
	string normalizedName = "";
	string particlesToRemove[] = { "DE","DO", "DA", "DAS", "DOS", "E" };
	
	int startIndex = 0;
	while (name[startIndex] == ' ') {
		startIndex++;
	}

	int endIndex = name.length() - 1;
	while (name[endIndex] == ' ') {
		endIndex--;
	}

	for (int i = startIndex; i <= endIndex; i++) {
		if (name[i] == 'E')
			continue;
		if (i + 1 <= endIndex && name[i] == 'D') {
			if (name[i + 1] == 'E' || name[i + 1] == 'O' || name[i + 1] == 'A') {
				i++;
				continue;
			}
			else if (i + 2 <= endIndex) {
				if (name[i + 1] == 'A' || name[i + 1] == 'O')
					if (name[i + 2] == 'S') {
						i += 2;
						continue;
					}
			}
			else
				normalizedName.push_back('D');
		}		
		else if (i > startIndex && name[i - 1] == ' ')
			continue;
		else if (islower(name[i]))
			normalizedName.push_back(toupper(name[i]));
		else
			normalizedName.push_back(name[i]);
	}	
	return normalizedName;
}

Fraction Exercises4::readFracc()
{
	Fraction fraction;
	char bar; // Char to hold the bar between the numbers, so as not to trigger the error flag
	cin >> fraction.numerator >> bar >> fraction.denominator; // Keeps the input values

	if (cin && bar == '/')
		return fraction;
	else {
		fraction.numerator = 0;
		fraction.denominator = 0;
		return fraction;
	}

	return Fraction();
}

Fraction Exercises4::reduceFracc(Fraction f)
{
	Exercises3 exercises3;
	int mdc = exercises3.gcd(f.numerator, f.denominator);

	Fraction frac = f;
	frac.numerator = frac.numerator / mdc;
	frac.denominator = frac.denominator / mdc;

	return frac;
}

Fraction Exercises4::addFracc(Fraction f1, Fraction f2)
{
	Fraction newFrac;
	newFrac.numerator = f1.numerator * f2.denominator + f2.numerator*f1.denominator;
	newFrac.denominator = f1.denominator * f2.denominator;
	newFrac = reduceFracc(newFrac);
	return newFrac;
}

Fraction Exercises4::subFracc(Fraction f1, Fraction f2)
{
	Fraction newFrac;
	newFrac.numerator = f1.numerator * f2.denominator - f2.numerator*f1.denominator;
	newFrac.denominator = f1.denominator * f2.denominator;
	newFrac = reduceFracc(newFrac);
	return newFrac;
}

Fraction Exercises4::multFracc(Fraction f1, Fraction f2)
{
	Fraction newFrac;
	newFrac.numerator = f1.numerator * f2.numerator;
	newFrac.denominator = f1.denominator * f2.denominator;
	newFrac = reduceFracc(newFrac);
	return newFrac;
}

Fraction Exercises4::divFracc(Fraction f1, Fraction f2)
{
	Fraction newFrac;
	newFrac.numerator = f1.numerator * f2.denominator;
	newFrac.denominator = f1.denominator * f2.numerator;
	newFrac = reduceFracc(newFrac);
	return newFrac;
}

void Exercises4::readIntArray(int a[], int nElem)
{
	for (int i = 0; i < nElem; i++) {
		cout << "Elemento numero " << i + 1 << "? ";
		cin >> a[i];
	}
}

int Exercises4::searchValueInIntArray(const int a[], int nElem, int value)
{
	for (int i = 0; i < nElem; i++) {
		if (a[i] == value)
			return i;
	}

	return -1;
}

int Exercises4::searchMultValuesInIntArray(const int a[], int nElem, int value, int index[])
{
	int numberOfElements = 0;
	int indexArrayIndex = 0;

	for (int i = 0; i < nElem; i++) {
		if (a[i] == value) {
			numberOfElements++;
			index[indexArrayIndex] = i;
			indexArrayIndex++;
		}
	}
	return numberOfElements;
}





