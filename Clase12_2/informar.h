int informar_ConsultaFacturacion(Contratacion* arrayC,int limite,Pantalla* pantallas, int lenPantallas, char* cuit);
int informar_ListarContrataciones(Contratacion* arrayC,int limite,Pantalla* pantallas, int lenPantallas);
int informar_ListarCantidadContratacionesImporte(Contratacion* arrayC,int limite,Pantalla* pantallas, int lenPantallas);
int informar_ListarPantallas(Pantalla* pantallas, int cantP);
int informar_ListarPantallasValorMenorPrecio(Pantalla* pantallas, int cantP);
int informar_ListarPantallasMayorPublicacion(Pantalla* pantallas, int cantP,Contratacion* contratacion);
int informe_contratacionesCuitDias(Contratacion* contratacion, int cantC, char cuit[]);
int informar_BuscarPorCuit(Contratacion* contrataciones, int cantC, char cuit[]);
int informe_pantallasContratacionCostosa(Pantalla* pantallas, int cantP, Contratacion* contrataciones, int cantC);
