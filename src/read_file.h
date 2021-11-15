#include <stdio.h>
#include <math.h>
#include "charmachine.h"
#include "wordmachine.h"
#include "matrix.h"
#include "Map.h"
#include "point.h"
#include "pesanan.h"
#include "item.h"

/* membaca file input dan mengisi  matrix peta, adjacency, dan queue pesanan */
void bacaFile (char namafile[], Matrix *peta, Matrix *adj, Queue *pesanan);
