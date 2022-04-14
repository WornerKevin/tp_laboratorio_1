//Kevin Worner 1A
#ifndef FUNCIONES_H_
#define FUNCIONES_H_

/**
 * @brief Funcion que ejecuta  el menu
 *
 */
void Menu(void);


/** \brief esta funcion sirve para generar un separador.
 *\void
 */
void MostrarSeparador(void);


/** \brief esta funcion muestra el menu de opciones.
 *
 * \param km int los kilometros ingresados.
 * \param y float precio que ingresara el usuario.
 * \param z float precio que ingresara el usuario.
 * \void.
 *
 */
void mostrarMenu(int km, float y, float z);


/** \brief toma la opcion del menu y la retorna.
 *\return int retorna la opcion elegida y validada.
 */
int tomarOpcion(void);

/** \brief pide los kilometros al usuario, los valida y los retorna.
 *\return int retorna los km ingresados.
 */
int pedirKm(void);

/**
 * @brief con un mensaje que pasa por parametro se le dice al usuario que ingrese los precios
 *  se los valida y se retorna el valor ingresado.
 * @param mensaje se le pasa por parametro el mensaje que se le mostrara al usuario
 * @return retorna el precio ingresado.
 */
float tomarPrecio(char mensaje[]);


/** \brief calcula el descuento que realiza con tarjeta de debito.
 *
 * \param precio float el precio ingresado.
 * \return float retorna el precio final con debito.
 *
 */
float precioTarjetaDebito(float precio);


/** \brief calcula el aumento que realiza con tarjeta de credito.
 *
 * \param precio float el precio ingresado.
 * \return float retorna el precio final con tarjeta de credito.
 *
 */
float precioTarjetaCredito(float precio);


/** \brief calcula el precio basado en bitcoins, mediante su valor asignado por un define.
 *
 * \param precio float el precio ingresado.
 * \return float retorna el precio final con bitcoins.
 *
 */
float precioBitcoin(float precio);


/** \brief calcula el precio por kilometro.
 *
 * \param precio float el precio ingresado.
 * \param km int el kilometro ingresado.
 * \return float retorna el precio final por km.
 *
 */
float precioUnitario(float precio, int km);


/** \brief calcula la diferencia de precio entre las dos aerolineas.
 *
 * \param y float el precio ingresado de Aerolineas.
 * \param z float el precio ingresado de Latam.
 * \return float retorna la diferencia de precio.
 *
 */
float calcularDiferencia(float y,float z);


/** \brief realiza una carga forzada de datos sin la necesidad que el usuario ingrese.
 *
 * \param y float el precio ingresado de Aerolineas.
 * \param z float el precio ingresado de Latam.
 * \param km int los kilometros ingresados.
 * \void
 *
 */
void cargaForzada(int* km, float* y, float* z);


/**
 * @brief funcion que carga los resultados pasando las variables de los kilometros, precio
 * y por puntero las variables de los calculos del main
 *
 * @param km toma los kilometros enteros
 * @param y toma el precio ingresado de Aerolineas
 * @param z toma el precio ingresado de Latam
 * @param debA puntero que calcula y modifica la variable de debito Aerolineas del main
 * @param debL puntero que calcula y modifica la variable de debito Latam del main
 * @param credA puntero que calcula y modifica la variable de credito Aerolineas del main
 * @param credL puntero que calcula y modifica la variable de credito Latam del main
 * @param bitA puntero que calcula y modifica la variable de bitcoins Aerolineas del main
 * @param bitL puntero que calcula y modifica la variable de bitcoins Latam del main
 * @param preA  puntero que calcula y modifica la variable de precio unitario de Aerolineas del main
 * @param preL puntero que calcula y modifica la variable de precio unitario de Latam del main
 * @param dif puntero que calcula y modifica la variable de diferencia de precio del main
 */
void cargarResultados( int km ,float  y,float z, float* debA, float* debL, float* credA, float* credL, float* bitA, float* bitL, float* preA, float* preL, float* dif );



/**
 * @brief funcion que muestra los resultados ya cargados con printf
 *
 * @param km toma por parametro los kilometros del main
 * @param y toma por parametro el precio de Aerolineas del main
 * @param z toma por parametro el precio de Latam del main
 * @param debA toma por parametro los calculos de debito Aerolineas
 * @param debL toma por parametro los calculos de debito Latam
 * @param credA toma por parametro los calculos de credito Aerolineas
 * @param credL toma por parametro los calculos de credito Latam
 * @param bitA toma por parametro los calculos de bitcoin Aerolineas
 * @param bitL toma por parametro los calculos de bitcoin Latam
 * @param preA toma por parametro los calculos de precio unitario Aerolineas
 * @param preL toma por parametro los calculos de precio unitario Latam
 * @param dif toma por parametro los calculos de la diferencia de precio
 */
void MostrarResultados( int km ,float  y,float z, float debA, float debL, float credA, float credL, float bitA, float bitL, float preA, float preL, float dif );
#endif /* FUNCIONES_H_ */
