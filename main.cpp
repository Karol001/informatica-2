#include <iostream>
using namespace  std;

int calcularLongitudCollatz(long long n) {
    int longitud = 1;
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
        longitud++;
    }
    return longitud;
}

bool esFechaValida(int mes, int dia) {
    if (mes < 1 || mes > 12)
        return false;

    switch (mes) {
    case 2:
        return dia >= 1 && dia <= 29; // Febrero puede tener hasta 29 días en un año bisiesto
    case 4:
    case 6:
    case 9:
    case 11:
        return dia >= 1 && dia <= 30; // Abril, Junio, Septiembre y Noviembre tienen máximo 30 días
    default:
        return dia >= 1 && dia <= 31; // Los demás meses tienen máximo 31 días
    }
}


int Potencia(int base, int exponente);

int sumaDigitosElevados(int numero) {
    int suma = 0;
    while (numero > 0) {
        int digito = numero % 10;
        suma += Potencia(digito, digito); // Llamada a la función Potencia
        numero /= 10;
    }
    return suma;
}

bool EsVocal(char letra);
#define pi 3.141689
int main()
{
    int opcion=1;

    cout<<"***** Bienvenido a la practica 1 *****"<<endl;
    while(opcion!=0)
    {
        cout<<"\nSeleccione una opcion"<<endl;
        cout<<"1.Determinador de Tipo de Carácter: Vocal o Consonante"<<endl;
        cout<<"2.Calculador de Dinero en Billetes y Monedas"<<endl;
        cout<<"3.Validador de Fechas"<<endl;
        cout<<"4.Calcular la hora final"<<endl;
        cout<<"5.Patrón de asteriscos"<<endl;
        cout<<"6.Para hallar la potencia"<<endl;
        cout<<"7.Fibonacci"<<endl;
        cout<<"8.Suma de Múltiplos Menores"<<endl;
        cout<<"9.Suma de los digitos elevados de un número"<<endl;
        cout<<"10.Enesimo número primo"<<endl;
        cout<<"11.Calcular Mínimo Común Múltiplo"<<endl;
        cout<<"12.Calcular Máximo factor primo"<<endl;
        cout<<"13.Suma de números primos menores que un número dado"<<endl;
        cout<<"14.Numeros palindromos"<<endl;
        cout<<"15.Matriz de espiral"<<endl;
        cout<<"16.Serie de Collatz"<<endl;
        cout<<"17.Secuencia de números triangulares"<<endl;

        cout<<"0.Para salir"<<endl;
        cin>>opcion;

        switch (opcion) {
        case 1:
        {
            char letra;
            cout<<"Ingrese un caracter"<<endl;
            cin>>letra;
            if((letra>=65 && letra<=90)||(letra>=97 && letra<=122))
            {
                if(EsVocal(letra))
                    cout<<letra<< " es vocal"<<endl;
                else
                    cout <<letra<<" es consonante"<<endl;
            }
            else
                cout<<letra<<" no es una letra"<<endl;
        }
        break;
        case 2:
        {
            int cantidad;
            int billetes[] ={50000, 20000, 10000, 5000, 2000, 1000};
            int monedas[] = {500, 200, 100, 50};

            cout << "Ingrese la cantidad de dinero: ";
            cin >> cantidad;

            for (int i = 0; i < 6; ++i) {
                int cantidad_billete = cantidad / billetes[i];
                cantidad -= cantidad_billete * billetes[i];
                cout << billetes[i] << " : " << cantidad_billete << endl;
            }

            for (int i = 0; i < 4; ++i) {
                int cantidad_moneda = cantidad / monedas[i];
                cantidad -= cantidad_moneda * monedas[i];
                cout << monedas[i] << " : " << cantidad_moneda << endl;
            }

            if (cantidad > 0) {
                cout << "Faltante: " << cantidad << endl;
            }
        }
        break;
        case 3:
        {

            int mes, dia;

            cout << "Ingrese el mes: ";
            cin >> mes;
            cout << "Ingrese el dia: ";
            cin >> dia;

            if (!esFechaValida(mes, dia)) {
                cout << dia << "/" << mes << " es una fecha invalida." << endl;
            } else {
                if (mes == 2 && dia == 29) {
                    cout << dia << "/" << mes << " es valida en bisiesto." << endl;
                } else {
                    cout << dia << "/" << mes << " es una fecha valida." << endl;
                }
            }
        }
        break;
        case 4:
        {
            int hora, duracion, horas, minutos;

            cout << "Ingrese la hora: ";
            cin >> hora;
            cout << "Ingrese la duracion: ";
            cin >> duracion;

            int hora_original = hora / 100;
            int minutos_original = hora % 100;
            int horas_duracion = duracion / 100;
            int minutos_duracion = duracion % 100;

            horas = hora_original + horas_duracion;
            minutos = minutos_original + minutos_duracion;

            if (minutos >= 60) {
                minutos -= 60;
                horas++;
            }

            horas %= 24;

            cout << "La hora es ";
            if (horas < 10) cout << "0"; // Añadir un cero al principio si es necesario
            cout << horas << minutos << endl;


        }
        break;
        case 5:
        {
            int tamano;

            cout << "Ingrese el tamano del patron (numero impar): ";
            cin >> tamano;

            if (tamano % 2 == 0) {
                cout << "El tamano ingresado no es impar." << endl;
                return 1;
            }

            for (int i = 1; i <= tamano / 2 + 1; i++) {
                int num_espacios = tamano / 2 + 1 - i;
                int num_asteriscos = 2 * i - 1;

                for (int j = 0; j < num_espacios; j++) {
                    cout << " ";
                }
                for (int j = 0; j < num_asteriscos; j++) {
                    cout << "*";
                }
                cout << endl;
            }

            for (int i = tamano / 2; i >= 1; i--) {
                int num_espacios = tamano / 2 + 1 - i;
                int num_asteriscos = 2 * i - 1;

                for (int j = 0; j < num_espacios; j++) {
                    cout << " ";
                }
                for (int j = 0; j < num_asteriscos; j++) {
                    cout << "*";
                }
                cout << endl;
            }
        }break;
        case 6:{
            int elementos;
            double euler = 1.0;
            bool redondear = false; // Bandera para indicar si necesitamos redondear

            cout << "Ingrese el numero de elementos para la aproximacion: ";
            cin >> elementos;

            double factorial = 1.0; // Inicializar el factorial en 0!
            for (int i = 1; i <= elementos; ++i) {
                factorial *= i; // Calcular el factorial de i
                euler += 1.0 / factorial; // Sumar el término correspondiente a euler
            }

            if (int(euler * 1000) % 10 >= 5) {
                redondear = true;
            }

            if (redondear) {
                euler = int(euler * 100 + 0.5) / 100.0;
            }

            cout << "e es aproximadamente: " << euler << endl;
        }break;
        case 7:{
            int n;
            int fib1 = 1, fib2 = 1, fib3 = 2;
            int suma_pares = 0;

            cout << "Ingrese un numero n: ";
            cin >> n;

            while (fib3 < n) {
                if (fib3 % 2 == 0) { // Verificar si el número es par
                    suma_pares += fib3; // Sumar el número par
                }
                fib1 = fib2;
                fib2 = fib3;
                fib3 = fib1 + fib2;
            }

            cout << "El resultado de la suma es: " << suma_pares << endl;
        }break;
        case 8:{
            int a, b, c;
            int suma = 0;

            cout << "Ingrese tres numeros a, b, c (separados por espacios): ";
            cin >> a >> b >> c;

            cout << "La suma de todos los multiplos de " << a << " y " << b << " menores a " << c << " es: ";
            bool primero = true;
            for (int i = 1; i < c; ++i) {
                if (i % a == 0 || i % b == 0) {
                    if (!primero) {
                        cout << " + ";
                    }
                    cout << i;
                    suma += i;
                    primero = false;
                }
            }

            cout << " = " << suma << endl;

        }break;
        case 9:{
            int numero;

            cout << "Ingrese un numero: ";
            cin >> numero;

            int resultado = sumaDigitosElevados(numero);

            cout << "El resultado de la suma es: " << resultado << endl;
        }break;
        case 10:{
            int n;
            cout << "Ingrese un numero n: ";
            cin >> n;

            int contador = 0;
            int numero = 2;

            while (true) {
                bool es_primo = true;
                for (int i = 2; i * i <= numero; ++i) {
                    if (numero % i == 0) {
                        es_primo = false;
                        break;
                    }
                }
                if (es_primo) {
                    ++contador;
                    if (contador == n) {
                        cout << "El primo numero " << n << " es: " << numero << endl;
                        break;
                    }
                }
                ++numero;
            }
        }break;
        case 11:{
            int n;

            cout << "Ingrese un numero: ";
            cin >> n;

            int mcm = 1;
            for (int i = 2; i <= n; ++i) {
                int a = mcm, b = i;
                while (b != 0) {
                    int temp = b;
                    b = a % b;
                    a = temp;
                }
                mcm *= (i / a);
            }

            cout << "El minimo comun multiplo es: " << mcm << endl;
        }break;
        case 12:{
            int numero;

            cout << "Ingrese un numero: ";
            cin >> numero;

            int maxFactorPrimo = 0;
            int numeroOriginal = numero;

            while (numero % 2 == 0) {
                maxFactorPrimo = 2;
                numero /= 2;
            }

            for (int i = 3; i * i <= numero; i += 2) {
                while (numero % i == 0) {
                    maxFactorPrimo = i;
                    numero /= i;
                }
            }

            if (numero > 2) {
                maxFactorPrimo = numero;
            }

            cout << "El mayor factor primo de " << numeroOriginal << " es: " << maxFactorPrimo << endl;
        }break;
        case 13: {
                int numero;

                cout << "Ingrese un numero: ";
                cin >> numero;

                int suma = 0;

                for (int i = 2; i < numero; ++i) {
                    bool esPrimo = true;

                    for (int j = 2; j * j <= i; ++j) {
                        if (i % j == 0) {
                            esPrimo = false;
                            break;
                        }
                    }

                    if (esPrimo) {
                        suma += i;
                    }
                }

                cout << "El resultado de la suma es: " << suma << endl;
        }break;
        case 14: {
            int mayorPalindromo = 0;
            int factor1 = 0, factor2 = 0;

            for (int i = 100; i < 1000; ++i) {
                for (int j = i; j < 1000; ++j) {
                    int producto = i * j;
                    // Verificar si el producto es un palíndromo y si es mayor que el mayor palíndromo encontrado hasta ahora
                    int num = producto;
                    int reverso = 0;
                    while (num > 0) {
                        reverso = reverso * 10 + num % 10;
                        num /= 10;
                    }
                    if (producto == reverso && producto > mayorPalindromo) {
                        mayorPalindromo = producto;
                        factor1 = i;
                        factor2 = j;
                    }
                }
            }

            std::cout << factor1 << "*" << factor2 << "=" << mayorPalindromo << std::endl;
        }break;
        case 15: {
            int size;
            cout << "Ingrese un número impar para el tamaño de la espiral (por ejemplo, 5, 7, 9, etc.): ";
            cin >> size;

            if (size % 2 == 0) {
                cout << "El número ingresado no es impar. Por favor, ingrese un número impar." << endl;
                return 1;
            }

            int spiral[size][size];

            int row = size / 2;
            int col = size / 2;
            int num = 1;

            int direction = 0; // 0: derecha, 1: abajo, 2: izquierda, 3: arriba
            int step = 1;
            int stepsCount = 0;

            while (num <= size * size) {
                spiral[row][col] = num;
                num++;

                switch (direction) {
                case 0: // Derecha
                    col++;
                    break;
                case 1: // Abajo
                    row++;
                    break;
                case 2: // Izquierda
                    col--;
                    break;
                case 3: // Arriba
                    row--;
                    break;
                }

                stepsCount++;
                if (stepsCount == step) {
                    stepsCount = 0;
                    direction = (direction + 1) % 4; // Cambiar la dirección
                    if (direction == 0 || direction == 2)
                        step++; // Aumentar el paso después de cada cambio de dirección horizontal o vertical
                }
            }

            cout << "La espiral resultante es:" << endl;
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    cout << spiral[i][j] << "\t";
                }
                cout << endl;
            }

            int sumDiagonals = 0;
            for (int i = 0; i < size; i++) {
                sumDiagonals += spiral[i][i]; // Diagonal principal
                sumDiagonals += spiral[i][size - i - 1]; // Diagonal secundaria
            }
            sumDiagonals -= spiral[size / 2][size / 2]; // Restar el elemento central si el tamaño es impar

            cout << "La suma de las diagonales de la espiral es: " << sumDiagonals << endl;
        }break;
        case 16: {
            int k;
            std::cout << "Ingrese un numero k: ";
            std::cin >> k;

            int semilla = 0;
            int maxTerminos = 0;

            for (int j = 2; j < k; ++j) {
                int terminos = calcularLongitudCollatz(j);
                if (terminos > maxTerminos) {
                    maxTerminos = terminos;
                    semilla = j;
                }
            }

            std::cout << "La serie mas larga es con la semilla: " << semilla << ", teniendo " << maxTerminos << " terminos." << std::endl;
        }break;
        case 17:{
            int k;
            std::cout << "Ingrese un numero k: ";
            std::cin >> k;

            int n = 1;
            int numeroTriangular = 1;
            while (true) {
                int divisores = 0;
                for (int i = 1; i * i <= numeroTriangular; ++i) {
                    if (numeroTriangular % i == 0) {
                        divisores++;
                        if (i * i != numeroTriangular) {
                            divisores++;
                        }
                    }
                }
                if (divisores > k) {
                    std::cout << "El numero es: " << numeroTriangular << " que tiene " << divisores << " divisores." << std::endl;
                    break;
                }
                n++;
                numeroTriangular += n;
            }
        }
        break;
        default:
            if (opcion != 0)
                cout << "opcion no valida" << endl;
            break;
        }
    }

}



int Potencia(int base, int exponente)
{
    int x=1;
    for(int i=0; i<exponente;i++)
        x*= base;
    return x;
}
bool EsVocal(char letra){
    if(letra>=97 && letra<=122)
        letra-=32;
    if(letra=='A' || letra=='E' || letra== 'I' || letra=='O'|| letra=='U')
        return true;
    else
        return false;
}
