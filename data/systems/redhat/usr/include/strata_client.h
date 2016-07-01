
#ifdef __cplusplus 
extern "C" {
#endif

typedef struct reportfile reportfile_t;

const char* strata_client_strerror( void );

reportfile_t* reportfile_start( int _issignature );
int reportfile_add_binding_from_string( reportfile_t* _file, 
                                        const char* _name, 
                                        const char* _value, 
                                        int _isbinary, 
                                        const char* _filename );
int reportfile_add_binding_from_memory( reportfile_t* _file, 
                                        const char* _name,  
                                        const void* _value, 
                                        size_t _size, 
                                        int _isbinary, 
                                        const char* _filename );
int reportfile_add_binding_from_namedfile( reportfile_t* _file, 
                                           const char* _name, 
                                           const char* _local_filename, 
                                           int _isbinary, 
                                           const char* _filename );
int reportfile_end( reportfile_t* );
int reportfile_write_to_file( reportfile_t* _file, const char* _outfile_name );
char* reportfile_as_string( reportfile_t* _file );
int reportfile_free( reportfile_t* _file );


const char* post_signature( const char* baseURL, 
			    const char* _cert_data,
                            const char* _username,
                            const char* _password,
                            const char* _signature );
const char* send_report_to_new_case( const char* baseURL,
				     const char* _cert_data,
                                     const char* _username,
                                     const char* _password,
                                     const char* _summary, 
                                     const char* _description, 
                                     const char* _component, 
                                     const char* _product, 
                                     const char* _version, 
                                     const char* _report_file_name );
const char* send_report_to_existing_case( const char* baseURL, 
					  const char* _cert_data,
                                          const char* _username,
                                          const char* _password,
                                          const char* _case_name, 
                                          const char* _report_file_name );

#ifdef __cplusplus 
}
#endif

