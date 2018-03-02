#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <algorithm> 
#include <iomanip>
#include <list>
#include "exercises.h"

using namespace std;


void Exercises::intro_exe()
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

void Exercises::exe1_1()
{
	char letra;

	cout << "Letra?  ";
	cin >> letra;
	cout << (int)letra << endl;
}

void Exercises::exe1_2()
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

void Exercises::exe1_3()
{
	double M, p, r; //initialize variables
	const double pi = 3.1415; //pi

	cout << "Sphere's material mass (Kg/m3) = "; cin >> p;
	cout << "Radius (m) = "; cin >> r;

	M = 4 / 3 * p * pi * pow(r, 3);

	cout << "Sphere's mass = " << M << " Kg" << endl;
}

void Exercises::exe1_4()
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

void Exercises::exe1_5()
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

float Exercises::exe1_6()
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

void Exercises::exe2_2_a()
{
	float a, b, c;

	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;
	cout << "c = "; cin >> c;

	cout << "max = " << max(a, max(b, c)) << endl;
	cout << "min = " << min(a, min(b, c)) << endl;
}

void Exercises::exe2_2_b()
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

void Exercises::exe2_2_c()
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

void Exercises::exe2_3()
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

void Exercises::exe2_4()
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

void Exercises::exe2_5()
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

void Exercises::exe2_6_a()
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

bool Exercises::isPrime(int number)  //Determines if a number is prime or not
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

void Exercises::exe2_6_b()
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

void Exercises::exe2_6_c()
{
	for (int i = 1; i < 10000; i++) {
		if (isPrime(i))
			cout << i << endl;
	}
	cout << endl;
}

void Exercises::exe2_7_a()
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

void Exercises::exe2_7_b()
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

void Exercises::exe2_9_a()
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

void Exercises::exe2_9_b()
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

void Exercises::exe2_9_c()
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

void Exercises::exe2_10_a()
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

void Exercises::exe2_10_b()
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

double Exercises::exe2_11_a() //serie que devolve o valor de pi
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

double Exercises::exe2_11_b() //serie que devolve o valor do numero de Neper
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

double Exercises::exe2_11_c() //serie que devolve o valor de pi
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

void Exercises::exe2_13()
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

void Exercises::exe2_14_a()
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

void Exercises::exe2_14_b()
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

int Exercises::exe3_8(int m, int n)
{ // Algoritmo de euclides

	if (m % n == 0) { // Se n for divisor de m
		return n;
	}
	else { // Se n nao for divisor, caso recursivo
		exe3_8(n, m % n);
	}
}

double Exercises::distance(double x1, double y1, double x2, double y2)
{
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

double Exercises::area(double x1, double y1, double x2, double y2, double x3, double y3)
{
	double a,b,c,s,total;
	a = distance(x1, y1, x2, y2);
	b = distance(x2, y2, x3, y3);
	c = distance(x3, y3, x1, y1);
	s = (a + b + c) / 2;
	total = sqrt(s*(s - a)*(s - b)*(s - c));
	return total;
}

bool Exercises::readFracc(int & numerator, int & denominator)
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

void Exercises::writeFracc(int numerator, int denominator)
{
	cout << numerator << '/' << denominator;
}

void Exercises::reduceFracc(int & numerator, int & denominator)
{

}

