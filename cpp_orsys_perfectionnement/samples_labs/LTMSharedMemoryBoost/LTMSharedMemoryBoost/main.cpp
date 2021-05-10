//
//  main.cpp
//  LTMSharedMemoryBoost
//

#include <iostream>

#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>

using namespace std;
using namespace boost::interprocess;

int main( int argc, char *argv[] ) {

     try {
         if( argc == 1 ) {
             std::cout << "process père" << std::endl;
         
            // shared memory
            shared_memory_object objet_partage( open_or_create ,"shared_memory" ,read_write );
            
            // dimensionner le shared memory
            objet_partage.truncate( 65536 );
            
            // organiser dans l'espace d'adressage
            mapped_region zone( objet_partage, read_write );
            
            // Ecriture dans la zone
            std::memset( zone.get_address(), 2, zone.get_size() );
             
            // lancement process fils
//            std::string s(argv[0]); s += " fils ";
//            if( 0 != std::system(s.c_str()) )
//                 return 1;
             
         }else {
             // process lecteur fils
             
             // ouvre un shared memory existant
             shared_memory_object objet_partage ( open_only, "shared_memory", read_only );
             
             // organiser dans l'espace d'adressage
             mapped_region zone( objet_partage, read_only );
             
             // teste si la mémoire est à 2
             char * mem = static_cast<char*>( zone.get_address() );
             for( std::size_t i = 0; i < zone.get_size(); ++i ) {
                 if( *mem++ != 2 ) {
                     cout << "erreur" << endl;
                 }else {
                     cout << i;
                 }
             }
             cout << endl;
             
             // destruction du partage mémoire
             shared_memory_object::remove( "shared_memory" );
         }
     
     }catch( interprocess_exception &ex ){
         std::cout << ex.what() << std::endl;
         return 1;
     }
    
    return 0;
}
