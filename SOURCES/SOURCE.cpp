#include "HEADER.h"

void Network_Device::GREET_CONNECTION_ESTABLISHED(){
std::cout<<"   _______________                        |*\\_/*|________"<<"\n"<<
"  |  ___________  |     .-.     .-.      ||_/-\\_|______  |"<<"\n"<<
"  | |           | |    .****. .****.     | |           | |"<<"\n"<<
"  | |   0   0   | |    .*****.*****.     | |   0   0   | |"<<"\n"<<
"  | |     -     | |     .*********.      | |     -     | |"<<"\n"<<
"  | |   \\___/   | |      .*******.       | |   \\___/   | |"<<"\n"<<
"  | |___     ___| |       .*****.        | |___________| |"<<"\n"<<
"  |_____|\\_/|_____|        .***.         |_______________|"<<"\n"<<
"    _|__|/ \\|_|_.............*.............._|________|_"<<"\n"<<
"   / ********** \\                          / ********** \\"<<"\n"<<
" /  ************  \\                      /  ************  \\"<<"\n"<<
"--------------------                    --------------------"<<"\n";
}
void Network_Device::GREET_PROGRAM_START(){

std::cout<<"|  \\/  |     | | | | | |                  / _ \\| |           ( )     |  ___|_   _| ___ \\     /  __ \\| |   |_   _|"<<"\n"<<
"| .  . | __ _| |_| |_| |__   _____      _/ /_\\ \\ | __ _  ___ |/ ___  | |_    | | | |_/ /_____| /  \\/| |     | |  "<<"\n"<<
"| |\\/| |/ _` | __| __| '_ \\ / _ \\ \\ /\\ / /  _  | |/ _` |/ _ \\  / __| |  _|   | | |  __/______| |    | |     | |  "<<"\n"<<
"| |  | | (_| | |_| |_| | | |  __/\\ V  V /| | | | | (_| | (_) | \\__ \\ | |     | | | |         | \\__/\\| |_____| |_ "<<"\n"<<
"\\_|  |_/\\__,_|\\__|\\__|_| |_|\\___| \\_/\\_/ \\_| |_/_|\\__, |\\___/  |___/ \\_|     \\_/ \\_|          \\____/\\_____/\\___/ "<<"\n"<<
"                                                   __/ |                                                         "<<"\n"<<
"                                                  |___/                                                          "<<"\n";
}
void Network_Device::HELP_PROMPT(){
    std::cout<<"~~~~~~~~~~ THIS IS THE HELP PAGE ~~~~~~~~~~~~~~~~~~~~~~\n\n"<<
    " -> $ls$ or $l$ or $dir$ or $la$ ----- List the contents of the current directory\n"<<
    " -> $cd DIRECTORY$ ----- Change the current directory to the specified one\n"<<
    " -> $mkdir DIRECTORY$ ----- Makes a directory with the name $DIRECTORY$\n"<<
    " -> $rmdir DIRECTORY$ ----- Removes a directory with the name $DIRECTORY$\n"<<
    " -> $rmfil FILE$ ----- Removes a file with the name $FILE$\n"<<
    " -> $exit$ ----- Closes connection and exits program\n"<<
    " -> $downd FILE$ ----- Downloads the file specified locally\n"<<
    " -> $uplod FILE$ ----- Uploads the file specified to the remote working directory\n"<<
    " -> $clear$ ----- Clears the screen\n"<<
    " -> $rn FILE1 FILE2$ ----- Gives FILE1 the name of FILE2\n"<<
    " -> $help$ ----- Makes this prompt appear\n\n";
}