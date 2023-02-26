macro( codegen input_file output_file args )
file(REAL_PATH ${input_file} infile BASE_DIRECTORY ${CMAKE_SOURCE_DIR} )
file(REAL_PATH ${output_file} outfile BASE_DIRECTORY ${CMAKE_BINARY_DIR} )
message( "Writing rules to expand ${infile} to ${outfile}")
set( GENCOMMAND ${Python3_EXECUTABLE} ${CMAKE_SOURCE_DIR}/codegen.py  
                ${infile} ${args} > ${outfile} )
add_custom_command(
        COMMAND ${GENCOMMAND}
        DEPENDS ${CMAKE_SOURCE_DIR}/codegen.py ${infile}
        OUTPUT  ${outfile} 
        COMMENT "Expanding Mako template ${infile} to ${outfile}" )
endmacro()