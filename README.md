# SIMPLE_FTP_CLI
A simple FTP client wrote in C++ using the sfml library. Run the program with -p inside the projects (p stands for project) and -s anywhere else (s stands for script). The only difference between these modes is that in script mode the working directory is where you upload and download files locally from the FTP server, whereas p actually organizes the downloaded and uploaded files a bit (Downloads are put in FTP_DOWNLOAD and you upload on the server using the files from FTP_UPLOAD).

!!! PLEASE NOTE THAT THE LINKER SEARCHES FOR LIBRARY FILES LIKE SFML-NETWORK.so IN YOUR /usr/lib FOLDER IF YOU ARE ON LINUX !!!
