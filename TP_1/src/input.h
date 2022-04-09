#ifndef INPUT_H_
#define INPUT_H_

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

void cargaForzada(void);
#endif /* INPUT_H_ */
