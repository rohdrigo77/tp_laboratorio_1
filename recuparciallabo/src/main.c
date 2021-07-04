#include "../inc/nexo.h"

int main()
{
    setbuf(stdout, NULL);
    eTrabajo listaTrabajos[MAX_TRABAJOS];
    eServicio listaServicios[MAX_SERVICIOS];
    eBicicleta listaBicicletas[MAX_BICICLETAS];
    eCliente listaClientes[MAX_CLIENTES];

    int estado;
    int estadoOpcion;
    int estadoMenu;
    int opcion;

    InicializarTrabajos(listaTrabajos, MAX_TRABAJOS);
    InicializarServicios(listaServicios, MAX_SERVICIOS);
    InicializarClientes(listaClientes, MAX_CLIENTES);
    InicializarBicicletas(listaBicicletas, MAX_BICICLETAS);

    HardcodeoDatosServicios(listaServicios, MAX_SERVICIOS, MIN_ID_SERVICIOS);
    HardcodeoDatosBicicletas(listaBicicletas, MAX_BICICLETAS, MIN_ID_BICICLETAS, MIN_ID_CLIENTES);
    HardcodeoDatosTrabajos(listaTrabajos, MAX_TRABAJOS, 1, MIN_ID_BICICLETAS, ANIO_ACTUAL);
    HardcodeoDatosClientes(listaClientes, MAX_CLIENTES, MIN_ID_CLIENTES);

    //ImprimirClientes(listaClientes,MAX_CLIENTES);
    //ImprimirBicicletas(listaBicicletas, listaClientes, MAX_BICICLETAS,MAX_CLIENTES);


    do
    {
    	do
    	{
			printf("1. ALTA\n");
			printf("2. MODIFICACION\n");
			printf("3. BAJA\n");
			printf("4. LISTAR TRABAJOS\n");
			printf("5. LISTAR SERVICIOS\n");
			printf("6. TOTAL $ POR SERVICIOS PRESTADOS\n");
			printf("7. LISTADO TRABAJOS POR MARCA\n");
			printf("8. LISTADO SERVICIO/S CON MAS TRABAJOS\n");
			printf("9. LISTADO SERVICIO/S CON DATOS DE BICICLETAS QUE SE LO REALIZARON\n");
			printf("10. CANTIDAD BICICLETA/S DE COLOR ROJO QUE REALIZARON UN SERVICIO (Elegir cuál servicio)\n");
			printf("11. LISTADO DE TRABAJOS ORDENADOS POR CLIENTE\n");
			printf("12. TOTAL POR CLIENTE\n");
			printf("13. Salir\n");
			opcion = PedirEntero("Elija una opcion:","Dato ingresado no válido");
			estadoOpcion = ValidarEnteroConRango(opcion,1,13);
			if (estadoOpcion != -1)
			{
				switch (opcion)
				{
					default:
						estadoMenu = 1;
						break;
				}
			}
    	}while(estadoMenu != 1);


        switch(opcion)
        {
            case 1:
            	estado = CargarTrabajo(listaTrabajos,listaServicios, listaBicicletas, listaClientes, MAX_TRABAJOS, MAX_SERVICIOS, MAX_BICICLETAS, MAX_CLIENTES, ANIO_ACTUAL , MAX_DESCRIPCION, MAX_MARCA, MIN_ID_BICICLETAS, MAX_COLOR);

            	if(estado != -1)
                {
                	printf("Trabajo cargado correctamente. \n");
                }
                else
                {
                	if (ValidarArrayOcupadoTrabajos(listaTrabajos,MAX_TRABAJOS) != OCUPADO)
                	{
                		printf("No hay más lugar para cargar trabajos. Elimine algunos y reintente. \n");
                	}
                	else
                	{
                		printf("Trabajo no cargado. No siguió las instrucciones correctamente. Reintente y lea con atención! \n");
                	}

                }
            	break;
            case 2:
            	estado = ModificarTrabajo(listaTrabajos,listaServicios, listaBicicletas, MAX_TRABAJOS,MAX_SERVICIOS, MAX_BICICLETAS, ANIO_ACTUAL, MAX_DESCRIPCION, MAX_MARCA);
                if(estado != -1)
                {
                	printf("Trabajo modificado correctamente. \n");
                }
                else
                {
					printf("Trabajo no modificado. No siguió las instrucciones correctamente. Reintente y lea con atención! \n");
                }
            	break;
            case 3:
            	DarDeBajaTrabajo(listaTrabajos, listaServicios, listaBicicletas, MAX_TRABAJOS,MAX_SERVICIOS, MAX_BICICLETAS, MAX_DESCRIPCION, MAX_MARCA);
            	break;
            case 4:
            	estado = ListarTrabajos(listaTrabajos, listaServicios, listaBicicletas, MAX_TRABAJOS, MAX_SERVICIOS, MAX_BICICLETAS, MAX_DESCRIPCION, MAX_MARCA);

            	if (estado != 1)
                {
					printf("No hay trabajos cargados para mostrar! \n");
                }
            	break;
            case 5:
            	ImprimirServicios(listaServicios, MAX_SERVICIOS);
            	break;
            case 6:
				TotalEnPesosPorServicios(listaTrabajos, listaServicios, MAX_TRABAJOS, MAX_SERVICIOS, MAX_DESCRIPCION);
				break;
            case 7:
            	estado = TrabajosOrdenadosPorMarca(listaTrabajos, listaServicios, listaBicicletas, MAX_TRABAJOS, MAX_SERVICIOS, MAX_BICICLETAS, MAX_DESCRIPCION, MAX_MARCA);
            	if (estado != 1)
                {
					printf("No hay trabajos cargados para mostrar! \n");
                }
            	break;
           case 8:
            	estado = ServicioConMasTrabajosRealizados(listaTrabajos, listaServicios, MAX_TRABAJOS, MAX_SERVICIOS, MAX_DESCRIPCION);
            	if (estado != 1)
                {
					printf("No hay trabajos cargados para mostrar! \n");
                }
            	break;
            case 9:
            	estado = ServiciosConDatosDeLasBicicletas(listaTrabajos, listaServicios, listaBicicletas, listaClientes, MAX_TRABAJOS, MAX_SERVICIOS, MAX_BICICLETAS, MAX_CLIENTES, MAX_DESCRIPCION, MAX_MARCA, MAX_NOMBRE,MAX_APELLIDO);
            	if (estado != 1)
                {
					printf("No hay trabajos cargados para mostrar! \n");
                }
            	break;
            case 10:
            	estado = CantidadBicicletasColorRojoPorServicio(listaTrabajos, listaServicios, listaBicicletas, MAX_TRABAJOS, MAX_SERVICIOS, MAX_BICICLETAS, MAX_DESCRIPCION, MAX_MARCA);
            	if (estado != 1)
                {
					printf("No hay trabajos cargados para mostrar! \n");
                }
            	break;
            case 11:
            	estado = ListarTrabajosSegunCliente(listaTrabajos,listaServicios,listaBicicletas,listaClientes,MAX_TRABAJOS, MAX_SERVICIOS, MAX_BICICLETAS, MAX_CLIENTES, MAX_DESCRIPCION, MAX_MARCA, MAX_COLOR, MAX_NOMBRE, MAX_APELLIDO);
            	if (estado != 1)
                {
					printf("No hay trabajos cargados para mostrar! \n");
                }
            	break;
            case 12:
            	estado = TotalServiciosPorCliente(listaTrabajos,listaServicios,listaBicicletas,listaClientes,MAX_TRABAJOS, MAX_SERVICIOS, MAX_BICICLETAS, MAX_CLIENTES, MAX_DESCRIPCION, MAX_MARCA, MAX_COLOR, MAX_NOMBRE, MAX_APELLIDO);
            	if (estado != 1)
                {
					printf("No hay trabajos cargados para mostrar! \n");
                }
            	break;

        }
    }while(opcion!=13);


    return 0;
}

