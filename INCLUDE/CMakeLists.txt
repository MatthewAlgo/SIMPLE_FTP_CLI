add_library(INCLUDE CPP.cpp)

install(TARGETS INCLUDE DESTINATION lib)
install(FILES Myinclude.h DESTINATION include)
install(FILES Mysecond.h DESTINATION include)