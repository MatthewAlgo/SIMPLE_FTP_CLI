#include "HEADER.h"
std::string *USR_IN = new std::string();
int main(int argc, char **argv)
{
    if (argc == 3)
    {
        std::string flag = argv[2];
        if (flag == "-s" || flag == "-p")
        {

            const std::string IP_AD = argv[1];
            Network_Device *NET_DEVICE = new Network_Device(argv[1]);
            system("clear"); // INITIALIZE AND CLEAR SCREEN
            NET_DEVICE->GREET_PROGRAM_START();
            NET_DEVICE->HELP_PROMPT();
            *NET_DEVICE->getFlag() = flag;
            NET_DEVICE->CONNECT_TO_ADDR();
            while (*NET_DEVICE->getStatus() == true)
            {
                std::cout << "!+~~COMM_HOST~~+@" << argv[1] << "##" << NET_DEVICE->getFTP()->getWorkingDirectory().getDirectory() << "-:$> ";
                std::getline(std::cin, *USR_IN);
                if (USR_IN->size() != 0)
                {
                    if (*USR_IN == "ls" || (*USR_IN == "dir") || *USR_IN == "la" || *USR_IN == "l")
                    {
                        NET_DEVICE->LIST_DIRECTORIES();
                    }
                    else if ((USR_IN->find("cd") == 0))
                    {
                        NET_DEVICE->CHANGE_DIRECTORY(USR_IN);
                    }
                    else if (USR_IN->find("rn") == 0)
                    {
                        auto COPY_BYTE_BY_BYTE{[](char * A, char * B){
                            for (size_t i{}; i < strlen(B); ++i)
                            {
                                A[i] = B[i];
                            }
                        }};
                        const char *STRING = USR_IN->c_str(); char* SECOND_WORD = new char[100];
                        char *TOKEN = new char[100]; char *PCHECK; char* FIRST_WORD = new char[100]; 
                        for (size_t i{}; i < strlen(STRING); ++i)
                        {
                            TOKEN[i] = STRING[i];
                        }
                        PCHECK = strtok(static_cast<char *>(TOKEN), " "); long long WORDS = 0;  auto LAMBDA_101 = [&]() {
                            while (PCHECK != NULL)
                            {
                                WORDS++;
                                if(WORDS == 2){
                                    COPY_BYTE_BY_BYTE(FIRST_WORD, PCHECK);
                                }else if(WORDS == 3){ COPY_BYTE_BY_BYTE (SECOND_WORD, PCHECK);}
                                PCHECK = strtok(NULL, " ");
                            }
                        }; LAMBDA_101();
                        if(WORDS == 3){
                            NET_DEVICE->RENAME_FILE(FIRST_WORD, SECOND_WORD);
                        }else{
                            std::cerr<<"~~Command not valid! Try again~~\n";
                        }
                        delete PCHECK;
                    }
                    else if (*USR_IN == "exit")
                    {
                        NET_DEVICE->getFTP()->disconnect();
                        std::cout << "Disconnected. Bye Bye!\n";
                        break;
                    }
                    else if (USR_IN->find("mkdir") == 0)
                    {
                        if (USR_IN->size() > 5)
                        {
                            std::string SUBSTRING = USR_IN->substr(6);
                            NET_DEVICE->MAKE_DIRECTORY(&SUBSTRING);
                        }
                        else
                        {
                            std::cout << "The given command is not correct. Please try again.\n";
                        }
                    }
                    else if (USR_IN->find("rmdir") == 0)
                    {
                        if (USR_IN->size() > 5)
                        {
                            std::string SUBSTRING = USR_IN->substr(6);
                            NET_DEVICE->REMOVE_DIRECTORY(&SUBSTRING);
                        }
                        else
                        {
                            std::cout << "The given command is not correct. Please try again.\n";
                        }
                    }
                    else if (USR_IN->find("rmfil") == 0)
                    {
                        if (USR_IN->size() > 5)
                        {
                            std::string SUBSTRING = USR_IN->substr(6);
                            NET_DEVICE->REMOVE_FILE(&SUBSTRING);
                        }
                        else
                        {
                            std::cout << "The given command is not correct. Please try again.\n";
                        }
                    }
                    else if (USR_IN->find("downd") == 0)
                    {
                        if (USR_IN->size() > 5)
                        {
                            std::string SUBSTRING = USR_IN->substr(6);
                            NET_DEVICE->DOWNLOAD_REMOTE(&SUBSTRING);
                        }
                        else
                        {
                            std::cout << "The given command is not correct. Please try again.\n";
                        }
                    }
                    else if (USR_IN->find("clear") == 0)
                    {
                        system("clear");
                        NET_DEVICE->GREET_CONNECTION_ESTABLISHED();
                    }
                    else if (*USR_IN == "help")
                    {
                        NET_DEVICE->HELP_PROMPT();
                    }
                    else if (USR_IN->find("uplod") == 0)
                    {
                        if (USR_IN->size() > 5)
                        {
                            std::string SUBSTRING = USR_IN->substr(6);
                            NET_DEVICE->UPLOAD_REMOTE(&SUBSTRING);
                        }
                        else
                        {
                            std::cout << "The given command is not correct. Please try again.\n";
                        }
                    }
                    else
                    {
                        std::cout << "~Command not recognized. Please try again~\n";
                    }
                    USR_IN->clear();
                }
                else
                {
                    std::cout << "~Command not recognized. Please try again~\n";
                }
                NET_DEVICE->getFTP()->keepAlive();
            }
        }
        else
        {
            std::cout << "\nThe flag is not known. Quitting...\n";
        }
    }
    else
    {
        std::cout << "\nThe script command is not known! Quitting...\n";
    }
}