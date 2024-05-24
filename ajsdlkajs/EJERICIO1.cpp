/*) Se dispone de un conjunto de inscripciones de alumnos a examen en el mes de mayo.
Cada inscripción tiene los siguientes datos: nombre y apellido, número de legajo, código de materia, día, mes y anio
del examen. Los datos finalizan con un número de legajo igual a cero.
Desarrollar un programa que a partir del ingreso de las inscripciones por teclado, genere un archivo binario de
inscripción de alumnos a exámenes finales DIAFINALES.DAT, según el siguiente diseño:
a.1 Nro. de legajo a.2 Código de materia
a.3 Día del examen a.4 Mes del examen
a.5 Año del examen a.6 Nombre-Apellido*/

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct inscripcion
{
    char NombreYApellido[50];
    int legajo,CodMateria,dia,mes,anio;
    
};
void mostrar (FILE *archivo);


int main()
{
    FILE *archFinales;
  archFinales = fopen("DIAFINALES.dat", "wb");
  if (archFinales == NULL)
    cout << "ERROR" << endl;
  else
  {
      inscripcion insc;
      cout<<"Ingrese numero de legajo (0 para finalizar)"<<endl;
      cin>>insc.legajo;
      while (insc.legajo!=0)
      {
          cout<<"Ingrese nombre y apellido"<<endl;
          fflush(stdin);
          cin.getline(insc.NombreYApellido,50);
          cout<<"Ingrese codigo de materia"<<endl;
          cin>>insc.CodMateria;
          cout << "Mes del examen: "; 
          cin >> insc.mes;
          cout << "Dia del examen: ";
          cin >> insc.dia;
          cout << "Ano del examen: ";
          cin >> insc.anio;
          fwrite(&insc,sizeof(inscripcion),1,archFinales);
          cout<<"Ingrese numero de legajo (0 para finalizar)"<<endl;
          cin >> insc.legajo;
      }
    fclose(archFinales);
    mostrar(archFinales);
  }
  return 0;
}

void mostrar (FILE*archivo)
{
    archivo = fopen("DIAFINALES.dat", "rb");
  if (archivo == NULL)
    cout << "ERROR" << endl;
  else
  {
    inscripcion inscp;
    fread(&inscp, sizeof(inscripcion), 1, archivo);
    while (!feof(archivo))
    {
      cout << endl;
      cout << "a.1 " << inscp.legajo << "    "
           << "a.2 " << inscp.CodMateria << endl;
      cout << "a.3 " << inscp.dia << "    "
           << "a.4 " << inscp.mes << endl;
      cout << "a.5 " << inscp.anio << "    "
           << "a.6 " << inscp.NombreYApellido << endl;
      fread(&inscp, sizeof(inscripcion), 1, archivo);
    }
    fclose(archivo);
  }
}

