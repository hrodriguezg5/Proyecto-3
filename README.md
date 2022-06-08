## Manual de uso de la Aplicacion

### Configuraciones
Las configuraciones de entorno para el optimo funcionamiento de la aplicacion son las siguientes

- Windows 8.1/10/11 (tambien ejecutable en linux)
- Dev c++ como lector y compilador del archivos .cpp
- Entorno de base de datos (MySQL) con los siguientes datos: 
  1. alojo de la base de datos: "localhost"
  2. usuario de la base de datos "root"
  3. contraseña de la base de datos: "Accesorios1"
  4. nombre de la base de datos: "proyecto-3"
  5. puerto: "3306"

### NOTA
_El uso de este programa en cualquier entorno con especificaciones similares no deberia afectar en el rendimiento o procedimiento de trabajo del programa sin embargo estos son los recomendados por ser el entorno en el cual fue probado y ejecutado con exito_

### Uso de la aplicacion

La aplicacion esta diseñada unica y exclusivamente para la manipulacion de datos de una base de datos MySQL en memoria, los cambios de uso de estos podrian afectar el rendimiento o funcionamiento de la misma

## Introduccion de datos en la aplicacion

Debido al metodo de manipulacion de archivos que la aplicacion posee estos datos deben ser agregados de forma correcta para el optimo funcionamiento de la aplicacion el tipo de datos que debe ingresar seran listados junto a su respectivo tipo de dato de uso para la optima utilizacion del programa

- Clave: ***Numerico***
- Nombre: ***Alfanumerico*** (si ingresa un valor que no sea alfabetico se almacenara como un dato alfanumerico asi que no podra operar con dicho valor este campo es exclusivamente para el almacenamiento de datos con los cual se recomienda utilizar unicamente datos alfabeticos)
- Correo: ***Alfanumerico*** (permite la intruccion de cualquier tipo de dato incluyendo datos especiales
- Fecha de nacimiento: ***alfanumerico*** (debido a las distintas forma de almacernar una fecha desde ___dd/mm/aaaa___ hasta ___dd "de" mm "del" aaaa___ por estas caracteristicas la forma de ingresar la fecha de nacimiento puede ser introducida de cualquier forma)
- Telefono: ***Numerico*** (Se deberan ingresar unicamente los 8 numeros del numero telefonico sin caracteres especiales como "+" o "-" debido a la forma de tratar con este dato)
- Direccion: ***alfanumerico*** (se aplican la misma logica que en el apartado de la fecha de nacimiento)
- Grado ***alfanumerico*** (se puede escribir de forma numerica o alfabetica sin generar problema alguno)
- seccion ***alfanumerico*** (se puede escribir de forma numerica o alfabetica sin generar problema alguno)


cualquier dato introducido de forma erronea o intencionada con un formato diferente al especificado en los puntos anteriores puede conllevar a un error de trabajo de la aplicacion.
