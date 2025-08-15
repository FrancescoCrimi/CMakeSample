# Impostazioni globali (opzionale, ma consigliato per coerenza)
# Verranno applicate a tutti i sottoprogetti, a meno che non vengano sovrascritte.

# Standard C (es. C11, C17, C99)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF) # Disabilita estensioni specifiche del compilatore

# Standard C++ (es. C++17, C++20)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) # Disabilita estensioni specifiche del compilatore

# Posiziona il codice indipendente (utile per librerie condivise, ma buona pratica in generale)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Aggiunge la directory <progetto_root>/cmake alla lista dei moduli
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
