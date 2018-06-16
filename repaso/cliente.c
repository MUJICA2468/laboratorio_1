

Cliente* cliente_new()
{
    return (Cliente*) malloc(sizeof(Cliente));
}

void cliente_delete(Cliente* this)
{
    free(this);
}


int cliente_setEdad(Cliente* this,int edad)
{
    int retorno = -1;
    if(this != NULL && !validarEdad(edad))
    {
        this->edad = edad;
        retorno = 0;

    }
    return retorno;
}

int cliente_getEdad(Cliente* this,int* edad)
{
    int retorno = -1;
    if(this != NULL && edad != NULL)
    {
        *edad = this->edad;
        retorno = 0;
    }
    return retorno;
}

static int cliente_setId(Cliente* this)
{
    int retorno = -1;
    static int ultimoId = -1;
    if(this != NULL)
    {
        ultimoId++;
        this->idCliente = ultimoId;
        retorno = 0;
    }
    return retorno;
}
