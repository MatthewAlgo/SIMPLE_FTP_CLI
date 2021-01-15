# SIMPLE_FTP_CLI
A simple FTP client wrote in C++ using the sfml library. Run the program with "./Program **IP ADDR** -p" inside the projects (p stands for project) and "./Program **IP ADDR** -s" anywhere else (s stands for script). The only difference between these modes is that in script mode the working directory is where you upload and download files locally from the FTP server, whereas p actually organizes the downloaded and uploaded files a bit (Downloads are put in FTP_DOWNLOAD and you upload on the server using the files from FTP_UPLOAD).

Example program calls:
./Program 192.168.0.248 -s
./Program 192.168.0.248 -p

I wrote a script that builds the program using the files from SOURCES. It's called build.sh

DEPENDENCIES:
The following dependencies should be available through a package manager: **libsfml-dev**

!!! PLEASE NOTE THAT THE LINKER SEARCHES FOR LIBRARY FILES LIKE SFML-NETWORK.so IN YOUR /usr/lib FOLDER IF YOU ARE ON LINUX !!!
