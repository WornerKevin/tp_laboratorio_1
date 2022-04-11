#ifndef FUNCIONES_H_
#define FUNCIONES_H_

void MostrarSeparador(void);

void mostrarMenu(int km, float y, float z);

int tomarOpcion(void);

int pedirKm(void);

float tomarPrecio(void);

float precioTarjetaDebito(float precio);

float precioTarjetaCredito(float precio);

float precioBitcoin(float precio);

float precioUnitario(float precio, int km);

float calcularDiferencia(float y,float z);

void cargaForzada(int km, float y, float z);
#endif /* FUNCIONES_H_ */
