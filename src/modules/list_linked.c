#include "list_linked.h"

#include <stdio.h>
#include <stdlib.h>

void CreateList(List *l) {
    FIRST(*l) = NULL;
}

boolean isEmptyLL(List l) {
    return FIRST(l) == NULL;
}

ElType getElmt(List l, int idx) {
    Address p;

    p = l;
    if (!(idx == lengthListLinked(l))) {
        for (int i = 0; i < idx; i++) {
            p = NEXT(p);
        }
        return INFO(p);
    } else {
        return 0;
    }
}

void setElmt(List *l, int idx, ElType val) {
    int i;
    Address p;

    i = 0;
    p = *l;
    if (idx == lengthListLinked(*l)) {
        insertLastLL(l, val);
    } else {
        while (i < idx) {
            i++;
            p = NEXT(p);
        }
        INFO(p) = val;
    }
}

int indexOfLL(List l, ElType val) {
    Address p;
    boolean found;
    int i;

    p = l;
    found = false;
    i = 0;

    while (p != NULL && !found) {
        if (INFO(p) == val) {
            found = true;
        } else {
            p = NEXT(p);
            i++;
        }
    }
    if (found) {
        return i;
    } else {
        return IDX_UNDEF;
    }
}

void insertFirst(List *l, ElType val) {
    Address p;

    p = newNode(val);
    if (p != NULL) {
        NEXT(p) = *l;
        *l = p;
    }
}

void insertLastLL(List *l, ElType val) {
    Address p, last;

    if (isEmptyLL(*l)) {
        insertFirst(l, val);
    } else {
        p = newNode(val);
        if (p != NULL) {
            last = *l;
            while (NEXT(last) != NULL) {
                last = NEXT(last);
            }
            NEXT(last) = p;
        }
    }
}

void insertAt(List *l, ElType val, int idx) {
    Address p, loc;
    int i;

    if (idx == 0) {
        insertFirst(l, val);
    } else if (idx == lengthListLinked(*l)) {
        insertLastLL(l, val);
    } else {
        p = newNode(val);
        if (p != NULL) {
            loc = *l;
            i = 0;
            while (i < idx - 1) {
                loc = NEXT(loc);
                i++;
            }
            NEXT(p) = NEXT(loc);
            NEXT(loc) = p;
        }
    }
}

void deleteFirst(List *l, ElType *val) {
    Address p;

    p = *l;
    *val = INFO(p);
    *l = NEXT(p);
    free(p);
}

void deleteLastLL(List *l, ElType *val) {
    Address p, loc;

    p = *l;
    loc = NULL;
    while (NEXT(p) != NULL) {
        loc = p;
        p = NEXT(p);
    }
    if (loc == NULL) {
        *l = NULL;
    } else {
        NEXT(loc) = NULL;
    }
    *val = INFO(p);
    free(p);
}

void deleteAt(List *l, int idx, ElType *val) {
    Address p, loc;
    int ctr;

    if (idx == 0) {
        deleteFirst(l, val);
    } else {
        ctr = 0;
        loc = *l;
        while (ctr < idx - 1) {
            ctr++;
            loc = NEXT(loc);
        }
        p = NEXT(loc);
        *val = INFO(p);
        NEXT(loc) = NEXT(p);
        free(p);
    }
}

void displayListLinked(List l) {
    Address p;

    p = l;
    if (isEmptyLL(l)) {
        printf("[]");
    } else {
        printf("[");
        while (NEXT(p) != NULL) {
            printf("%d", INFO(p));
            printf(",");
            p = NEXT(p);
        }
        printf("%d", INFO(p));
        printf("]");
    }
}

int lengthListLinked(List l) {
    int i;
    Address p;

    i = 0;
    p = l;
    while (p != NULL) {
        i++;
        p = NEXT(p);
    }
    return i;
}

List concat(List l1, List l2) {
    List l3;
    Address p;

    CreateList(&l3);
    p = l1;

    while (p != NULL) {
        insertLastLL(&l3, INFO(p));
        p = NEXT(p);
    }

    p = l2;
    while (p != NULL) {
        insertLastLL(&l3, INFO(p));
        p = NEXT(p);
    }

    return l3;
}
