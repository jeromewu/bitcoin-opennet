SRC_DIR = ..
BOOST_LIBS = -L/usr/lib64 -lboost_system -lboost_filesystem -lboost_program_options -lboost_thread -lboost_chrono 
BDB_LIBS = -ldb_cxx
PROTOBUF_LIBS = -lprotobuf -pthread -lpthread 
SSL_LIBS = -lssl -lcrypto 
CRYPTO_LIBS = -lcrypto 
CPPFLAGS =  -DBOOST_SPIRIT_THREADSAFE -DHAVE_BUILD_INFO -D__STDC_FORMAT_MACROS  -U_FORTIFY_SOURCE -D_FORTIFY_SOURCE=2
CXXFLAGS = -g -O2 -Wall -Wextra -Wformat -Wformat-security -Wno-unused-parameter  -Wstack-protector -fstack-protector-all -fPIE

LIBS = $(BOOST_LIBS) $(BDB_LIBS) $(PROTOBUF_LIBS) $(SSL_LIBS) $(CRYPTO_LIBS)
FLAGS = $(CPPFLAGS) $(CXXFLAGS) -I$(SRC_DIR)
LDLIBS = -L$(SRC_DIR) -L$(SRC_DIR)/crypto -lbitcoin_common -lbitcoin_crypto

all: findhash

makeseeds:
	cat seeds.lst | ./makeseeds.py

findhash:
	g++ find-hash.cpp -o find-hash $(LDLIBS) $(FLAGS) $(LIBS) 

run:
	./find-hash
