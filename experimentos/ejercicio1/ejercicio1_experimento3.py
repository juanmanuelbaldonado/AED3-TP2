from random import randint

# Este script genera casos random con costo random y con una cantidad fija de trabajos,
# pero disminuyendo el costo máximo de los trabajos cuanto más adelante(mayor indice) estos se encuentren
# Ej: El costo máximo de los 10 primeros trabajos es 100, pero el de los
# últimos 10 es 10

trabajos_a_organizar = 100
repeticiones = 10
costo_min = 1
costo_max = 100
costo_max_step = 10

for costo_m in range(0, costo_max // costo_max_step):
    for r in range(0, repeticiones):
        print('{}'.format(trabajos_a_organizar))

        for trabajos in range(1, trabajos_a_organizar + 1):
            trabajo_costos = []
            for costo_preparacion in range(1, trabajos + 1):
                trabajo_costos.append(randint(costo_min, costo_max - costo_max_step * (trabajos//10 - 1)))

            print("{}".format(" ".join(str(i) for i in trabajo_costos)))

print("0")