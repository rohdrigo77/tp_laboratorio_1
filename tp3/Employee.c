#include "Employee.h"

Employee* employee_new()
{
	Employee* pEmpleado;

	pEmpleado = (Employee*) malloc(sizeof(Employee));

	if(pEmpleado != NULL)
	{
		pEmpleado->id = 0;
		strcpy(pEmpleado->nombre, " ");
		pEmpleado->horasTrabajadas = 0;
		pEmpleado->sueldo = 0;
	}

	return pEmpleado;

}

Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* pEmpleado;
	int auxID;
	int auxHoras;
	int auxSueldo;

	pEmpleado = employee_new();

	if (pEmpleado != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr !=  NULL)
	{
		auxID = atoi(idStr);
		auxHoras = atoi(horasTrabajadasStr);
		auxSueldo = atoi(sueldoStr);



		employee_setId(pEmpleado,auxID);
		employee_setNombre(pEmpleado,nombreStr);
		employee_setHorasTrabajadas(pEmpleado,auxHoras);
		employee_setSueldo(pEmpleado,auxSueldo);
	}

	return pEmpleado;
}

Employee* employee_newParametrosConInt(int idStr, char* nombreStr, int horasTrabajadasStr, int sueldoStr)
{
	Employee* pEmpleado;

	pEmpleado = employee_new();

	if (pEmpleado != NULL && nombreStr)
	{

		employee_setId(pEmpleado,idStr);
		employee_setNombre(pEmpleado,nombreStr);
		employee_setHorasTrabajadas(pEmpleado,horasTrabajadasStr);
		employee_setSueldo(pEmpleado,sueldoStr);
	}

	return pEmpleado;
}

void employee_delete(Employee* this)
{

	if(this != NULL)
	{
		free(this);
	}

}

int employee_setId(Employee* this,int id)
{
	int estado;

	estado = 0;

	if (this != NULL)
	{
		this->id = id;
		estado = 1;
	}

	return estado;

}
int employee_getId(Employee* this,int* id)
{
	int estado;

	estado = -1;

	if (this != NULL)
	{
		*id = this->id;
		estado = 1;
	}

	return estado;

}

int employee_setNombre(Employee* this,char* nombre)
{
	int estado;

	estado = 0;

	if (this != NULL && nombre != NULL && strlen(nombre) > 0)
	{
		strncpy(this->nombre,nombre,128);
		estado = 1;
	}

	return estado;

}

int employee_getNombre(Employee* this, char* nombre)
{
	int estado;

	if (this != NULL && nombre != NULL)
	{
		strncpy(nombre,this->nombre,128);
		estado = 1;
	}

	return estado;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int estado;

	estado = 0;

	if (this != NULL)
	{
		this->horasTrabajadas = horasTrabajadas;
		estado = 1;
	}

	return estado;

}
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
	int estado;

	if (this != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		estado = 1;
	}

	return estado;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int estado;

	estado = 0;

	if (this != NULL)
	{
		this->sueldo = sueldo;
		estado = 1;
	}

	return estado;

}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int estado;

	if (this != NULL)
	{
		*sueldo = this->sueldo;
		estado = 1;
	}

	return estado;
}

int employee_showEmployee(Employee* miEmpleado)
{
	int estado;
	int auxId;
	char auxNombre[128];

	int auxHoras;
	int auxSueldo;

	//pNombre = (char*) malloc(sizeof(char) * 128);

	if (miEmpleado != NULL)
	{
		//printf("%4d %15s %15d %7d \n",miEmpleado->id,miEmpleado->nombre,miEmpleado->horasTrabajadas,miEmpleado->sueldo);
		estado = employee_getEmployee(miEmpleado,&auxId,auxNombre,&auxHoras,&auxSueldo);

		if (estado != -1)
		{
			printf("%4d %15s %15d %7d \n",auxId,auxNombre,auxHoras,auxSueldo);
			//printf("%4d %15s %15d %7d \n",miEmpleado->id,miEmpleado->nombre,miEmpleado->horasTrabajadas,miEmpleado->sueldo);
		}

	}
	else
	{
		printf("miEmpleado esta vacío. \n");
		estado = -1;
	}

	return estado;
}

int employee_getEmployee(Employee* miEmpleado, int* auxId, char* auxNombre, int* auxHoras, int* auxSueldo)
{
	int estado;

	if (miEmpleado != NULL)
	{
		employee_getId(miEmpleado,auxId);
		employee_getNombre(miEmpleado,auxNombre);
		employee_getHorasTrabajadas(miEmpleado,auxHoras);
		employee_getSueldo(miEmpleado,auxSueldo);
		estado = 1;
	}
	else
	{
		estado = -1;
	}

	return estado;


}

int employee_sortId(void* e1, void* e2)
{
    int estado;

    Employee* empleadoUno;
    Employee* empleadoDos;

	if(empleadoUno != NULL && empleadoDos != NULL)
	{
		empleadoUno=(Employee*) e1;
		empleadoDos=(Employee*) e2;

		if(empleadoUno->id > empleadoDos->id)
		{
			estado = 1;
		}
		else if(empleadoUno->id < empleadoDos->id)
		{
			estado = -1;
		}
		else
		{
			estado = 0;
		}
	}

	return estado;
}

int employee_sortNombre(void* e1, void* e2)
{
    int estado;

    Employee* empleadoUno;
    Employee* empleadoDos;

    if(e1 != NULL && e2 != NULL)
    {
        empleadoUno=(Employee*) e1;
        empleadoDos=(Employee*) e2;

        if((strcmp(empleadoUno->nombre, empleadoDos->nombre)) > 0)
        {
            estado = 1;
        }
        else if((strcmp(empleadoUno->nombre, empleadoDos->nombre)) < 0)
        {
            estado = -1;
        }
        else
        {
            estado = 0;
        }
    }

    return estado;
}

int employee_sortHorasTrabajadas(void* e1, void* e2)
{
    int estado;

    Employee* empleadoUno;
    Employee* empleadoDos;

    if(e1 != NULL && e2 != NULL)
    {
        empleadoUno = (Employee*)e1;
        empleadoDos = (Employee*)e2;

        if(empleadoUno->horasTrabajadas > empleadoDos->horasTrabajadas)
        {
            estado = 1;
        }
        else if(empleadoUno->horasTrabajadas < empleadoDos->horasTrabajadas)
        {
            estado = -1;
        }
        else
        {
            estado = 0;
        }
    }
    return estado;
}

int employee_sortSueldo(void* e1, void* e2)
{
    int estado;

    Employee* empleadoUno;
    Employee* empleadoDos;

    if(e1 != NULL && e2 != NULL)
    {
        empleadoUno=(Employee*) e1;
        empleadoDos=(Employee*) e2;

        if(empleadoUno->sueldo > empleadoDos->sueldo)
        {
            estado = 1;
        }
        else if(empleadoUno->sueldo < empleadoDos->sueldo)
        {
            estado = -1;
        }
        else
        {
            estado = 0;
        }
    }

    return estado;
}





