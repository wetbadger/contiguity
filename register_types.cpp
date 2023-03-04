/* register_types.cpp */

#include "register_types.h"

#include "core/class_db.h"
#include "contiguity.h"

void register_contiguity_types() {
    ClassDB::register_class<Contiguity>();
}

void unregister_contiguity_types() {
   // Nothing to do here in this example.
}
