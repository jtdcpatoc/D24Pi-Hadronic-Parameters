add_executable(MinimalExample MinimalExample.cpp)

target_link_libraries(MinimalExample PUBLIC D02pipipipi_binning_scheme)
target_link_libraries(MinimalExample PUBLIC ROOT::Physics ROOT::RIO ROOT::Tree)

install(TARGETS MinimalExample DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/../bin)

########

add_executable(BinningScheme Binning.cpp)

target_link_libraries(BinningScheme PUBLIC D02pipipipi_binning_scheme)
target_link_libraries(BinningScheme PUBLIC ROOT::Physics ROOT::RIO ROOT::Tree)

install(TARGETS BinningScheme DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/../bin)

########

add_executable(GenerateFlat GenerateFlat.cpp)

target_link_libraries(GenerateFlat PUBLIC D02pipipipi_binning_scheme)
target_link_libraries(GenerateFlat PUBLIC ROOT::Physics ROOT::RIO ROOT::Tree)

install(TARGETS GenerateFlat DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/../bin)

########

add_executable(Parameters Parameters.cpp)

target_link_libraries(Parameters PUBLIC D02pipipipi_binning_scheme)
target_link_libraries(Parameters PUBLIC ROOT::Physics ROOT::RIO ROOT::Tree)

install(TARGETS Parameters DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/../bin)

########

add_executable(FlippedBinning FlippedBinning.cpp)

target_link_libraries(FlippedBinning PUBLIC D02pipipipi_binning_scheme)
target_link_libraries(FlippedBinning PUBLIC ROOT::Physics ROOT::RIO ROOT::Tree)

install(TARGETS FlippedBinning DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/../bin)

########

add_executable(KKPiPiFlat KKPiPiFlat.cpp)

target_link_libraries(KKPiPiFlat PUBLIC D02pipipipi_binning_scheme)
target_link_libraries(KKPiPiFlat PUBLIC ROOT::Physics ROOT::RIO ROOT::Tree)

install(TARGETS KKPiPiFlat DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/../bin)

########

add_executable(KKPiPiBinning KKPiPiBinning.cpp)

target_link_libraries(KKPiPiBinning PUBLIC D02pipipipi_binning_scheme)
target_link_libraries(KKPiPiBinning PUBLIC ROOT::Physics ROOT::RIO ROOT::Tree)

install(TARGETS KKPiPiBinning DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/../bin)