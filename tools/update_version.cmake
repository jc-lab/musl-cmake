execute_process(
        COMMAND sh ${SCRIPT_FILE}
        OUTPUT_VARIABLE VERSION
)
message("INPUT_FILE = ${INPUT_FILE}")
message("OUTPUT_FILE = ${OUTPUT_FILE}")
message("VERSION = ${VERSION}")
configure_file(${INPUT_FILE} ${OUTPUT_FILE} @ONLY)
