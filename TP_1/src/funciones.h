//Kevin Worner 1A
#ifndef FUNCIONES_H_
#define FUNCIONES_H_


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

/** \brief pide el precio al usuario, los valida y los retorna.
 *\return float retorna el precio.
 */
float tomarPrecio(void);


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
void cargaForzada(int km, float y, float z);
#endif /* FUNCIONES_H_ */
