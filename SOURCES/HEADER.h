
#pragma once
#if not defined(MATEI_H)
#define MATEI_H
#if defined(__linux__) || defined(_WIN32) || defined(__APPLE__)

#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <thread>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <ctime>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <array>
#include <limits.h>
#include <unistd.h>
#include <string>

class Network_Device
{
private:
    std::string FLAG_S_P;
    sf::Ftp *FTP = new sf::Ftp();
    std::string *ADDRESS = new std::string();
    bool UP_CHECK = false;
    size_t PORT = 80;
    const char *ADDR = "127.0.0.1";

public:
    void GREET_CONNECTION_ESTABLISHED();
    void GREET_PROGRAM_START();
    void HELP_PROMPT();

    void CONNECT_TO_ADDR()
    {
        std::cout << "~~~CONNECTING TO " << *ADDRESS << "...\n";
        sf::Ftp::Response CONNECT_RESPONSE = FTP->connect(sf::IpAddress(*ADDRESS));
        if (*ADDRESS == "127.0.0.1")
        {
            std::cout << "\n~~Connecting to localhost (fallback)~~\n";
        }
        std::cout << "THE MESSAGE IS: " << CONNECT_RESPONSE.getMessage() << "\n";
        std::cout << "THE STATUS IS: " << CONNECT_RESPONSE.getStatus() << "\n";
        if (CONNECT_RESPONSE.isOk())
        {
            std::cout << "\n~~Connection established~~\n";
            UP_CHECK = true;
            std::string Username;
            std::string Passw;
            bool CorrLOGIN = false;
            while (!CorrLOGIN)
            {
                std::cout << "~~Please insert your username~~: ";
                std::getline(std::cin, Username);
                std::cout << "~~Please insert your password~~: ";
                std::getline(std::cin, Passw);
                if (FTP->login(Username, Passw).isOk())
                {
                    CorrLOGIN = true;
                }
                else
                {
                    std::cout << "\n~The credentials were not correct! Try again!~\n";
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    system("clear");
                    GREET_PROGRAM_START();
                }
            }
            system("clear");
            GREET_CONNECTION_ESTABLISHED();
        }
        else
        {
            std::cerr << "\n~~Something went wrong, Please try again later~~\n";
        }
    }
    void RENAME_FILE (char* FILENAME_SOURCE, char* FILENAME_DEST){
        if(FTP->renameFile(std::string(FILENAME_SOURCE), std::string(FILENAME_DEST)).isOk()){
            std::cout<<"~~Successfully renamed file "<<FILENAME_SOURCE<<" to "<<FILENAME_DEST<<"~~\n";
        }else{
            std::cout<<"~~Failed to rename file "<<FILENAME_SOURCE<<" to "<<FILENAME_DEST<<"~~\n";
        }
    }
    void CHANGE_DIRECTORY(std::string *USER_IN)
    {

        if (USER_IN->size() > 3)
        {
            std::string SEGMENT = USER_IN->substr(3);
            sf::Ftp::DirectoryResponse DIR_RESP = FTP->changeDirectory(SEGMENT);
            if (DIR_RESP.isOk())
            {
                std::cout << "\n~~WORKING DIRECTORY~~ " << FTP->getWorkingDirectory().getDirectory() << "\n";
            }
            else
            {
                std::cout << "\n~Command couldn't be processed. Please try again~\n";
            }
        }
        else
        {
            std::cout << "\n~Change directory command not recognized. Please try again~\n";
        }
    }

    void LIST_DIRECTORIES()
    {
        std::cout << "\n~~WORKING DIRECTORY~~ " << FTP->getWorkingDirectory().getDirectory() << "\n";
        sf::Ftp::ListingResponse LIST_RESP = FTP->getDirectoryListing();
        const std::vector<std::string> LIST_DIR = LIST_RESP.getListing();
        if (LIST_DIR.size() % 2 == 0)
        {
            for (std::vector<std::string>::const_iterator it = LIST_DIR.begin(); it != LIST_DIR.end(); it += 2)
            {
                std::cout << *it << "  ~~~~  " << *(it + 1) << "\n";
            }
        }
        else
        {
            for (std::vector<std::string>::const_iterator it = LIST_DIR.begin(); it != LIST_DIR.end() - 1; it += 2)
            {
                std::cout << *it << "  ~~~~  " << *(it + 1) << "\n";
            }
            std::cout << *(LIST_DIR.end() - 1) << "\n";
        }
    }
    void MAKE_DIRECTORY(std::string *DIRECTORY)
    {
        if (FTP->createDirectory(*DIRECTORY).isOk())
        {
            std::cout << "~Created directory " << *DIRECTORY << " at " << FTP->getWorkingDirectory().getDirectory() << "~\n";
        }
        else
        {
            std::cout << "~~Your directory couldn't be deleted~~\n";
        }
    }
    std::string GetExePath()
    {
        char result[PATH_MAX];
        ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
        return std::string(result, (count > 0) ? count : 0);
    }

    void REMOVE_DIRECTORY(std::string *DIRECTORY)
    {

        if (FTP->deleteDirectory(*DIRECTORY).isOk())
        {
            std::cout << "~Deleted directory " << *DIRECTORY << " from " << FTP->getWorkingDirectory().getDirectory() << "~\n";
        }
        else
        {
            std::cout << "~~Your directory couldn't be deleted or \"directory not found\"~~\n";
        }
    }
    void REMOVE_FILE(std::string* FILE){
        if (FTP->deleteFile(*FILE).isOk())
        {
            std::cout << "~Deleted file " << *FILE << " from " << FTP->getWorkingDirectory().getDirectory() << "~\n";
        }
        else
        {
            std::cout << "~~Your file couldn't be deleted or \"file not found\"~~\n";
        }
    }

    void DOWNLOAD_REMOTE(std::string *FILE)
    {
        if (FILE->size() != 0)
        {
            if (FLAG_S_P == "-s")
            {
                std::cout << "~~Downloading file " << FTP->getWorkingDirectory().getDirectory() + "/" + *FILE << " from server...~\n";
                std::cout << "~~To " << std::filesystem::current_path() << "...~~\n";
                // std::string CURRENT_WORKING_DIR = system("echo $(pwd) > /dev/null");
                sf::Ftp::Response RESP = FTP->download(FTP->getWorkingDirectory().getDirectory() + "/" + *FILE, std::filesystem::current_path(), sf::Ftp::Binary);

                if (RESP.isOk())
                {
                    std::cout << "Downloaded file " << FTP->getWorkingDirectory().getDirectory() + "/" + *FILE << " from " << FTP->getWorkingDirectory().getDirectory() << "~...\n";
                    std::cout << "~~To " << std::filesystem::current_path() << "...~~\n";
                    std::cerr << "STATUS: " << RESP.getStatus() << "\n";
                    std::cerr << "MESSAGE: " << RESP.getMessage() << "\n";
                    std::cerr << "SHA256sum: "<<system(std::string("sha256sum "+std::string(std::string(std::filesystem::current_path()) + "/" + *FILE)).c_str())<<"\n";
                    std::cerr << "MD5sum: "<<system(std::string("md5sum "+std::string(std::string(std::filesystem::current_path()) +"/" + *FILE)).c_str())<<"\n";
                }
                else
                {
                    std::cout << "Failed to download file " << FTP->getWorkingDirectory().getDirectory() + "/" + *FILE << " from " << FTP->getWorkingDirectory().getDirectory() << "~...\n";
                    std::cout << "~~To " << std::filesystem::current_path() << "...~~\n";
                    std::cerr << "STATUS: " << RESP.getStatus() << "\n";
                    std::cerr << "MESSAGE: " << RESP.getMessage() << "\n";
                }
            }
            else if (FLAG_S_P == "-p")
            {
                std::cout << "~~Downloading file " << FTP->getWorkingDirectory().getDirectory() + "/" + *FILE << " from server...~\n";
                std::cout << "~~To " << std::string(std::string(std::filesystem::current_path()) + "/FTP_DOWNLOAD") << "...~~\n";
                // std::string CURRENT_WORKING_DIR = system("echo $(pwd) > /dev/null");
                sf::Ftp::Response RESP = FTP->download(FTP->getWorkingDirectory().getDirectory() + "/" + *FILE, std::string(std::string(std::filesystem::current_path()) + "/FTP_DOWNLOAD"), sf::Ftp::Binary);

                if (RESP.isOk())
                {
                    std::cout << "Downloaded file " << FTP->getWorkingDirectory().getDirectory() + "/" + *FILE << " from " << FTP->getWorkingDirectory().getDirectory() << "~...\n";
                    std::cout << "~~To " << std::string(std::string(std::filesystem::current_path()) + "/FTP_DOWNLOAD") << "...~~\n";
                    std::cerr << "STATUS: " << RESP.getStatus() << "\n";
                    std::cerr << "MESSAGE: " << RESP.getMessage() << "\n";
                    std::cerr << "SHA256sum: "<<system(std::string("sha256sum "+std::string(std::string(std::filesystem::current_path()) + "/FTP_DOWNLOAD"+"/" + *FILE)).c_str())<<"\n";
                    std::cerr << "MD5sum: "<<system(std::string("md5sum "+std::string(std::string(std::filesystem::current_path()) + "/FTP_DOWNLOAD"+"/" + *FILE)).c_str())<<"\n";

                }
                else
                {
                    std::cout << "Failed to download file " << FTP->getWorkingDirectory().getDirectory() + "/" + *FILE << " from " << FTP->getWorkingDirectory().getDirectory() << "~...\n";
                    std::cout << "~~To " << std::string(std::string(std::filesystem::current_path()) + "/FTP_DOWNLOAD") << "...~~\n";
                    std::cerr << "STATUS: " << RESP.getStatus() << "\n";
                    std::cerr << "MESSAGE: " << RESP.getMessage() << "\n";
                }
            }
        }
        else
        {
            std::cout << "The given command is not correct. Please try again.\n";
        }
    }
    void UPLOAD_REMOTE(std::string *FILE)
    {
        if (FILE->size() != 0)
        {

            if (FLAG_S_P == "-p")
            {
                std::cout << "~~Uploading file " << std::string(std::string(std::filesystem::current_path()) + "/FTP_UPLOAD" + "/" + *FILE) << " from local device...~\n";
                std::cout << "~~To " << FTP->getWorkingDirectory().getDirectory() << "...~~\n";
                // std::string CURRENT_WORKING_DIR = system("echo $(pwd) > /dev/null");
                sf::Ftp::Response RESP = FTP->upload(std::string(std::string(std::filesystem::current_path()) + "/FTP_UPLOAD" + "/" + *FILE), FTP->getWorkingDirectory().getDirectory(), sf::Ftp::Binary);

                if (RESP.isOk())
                {
                    std::cout << "~~Uploaded file " << std::string(std::string(std::filesystem::current_path()) + "/FTP_UPLOAD" + "/" + *FILE) << " from local device...~\n";
                    std::cout << "~~To " << FTP->getWorkingDirectory().getDirectory() << "...~~\n";
                    std::cerr << "STATUS: " << RESP.getStatus() << "\n";
                    std::cerr << "MESSAGE: " << RESP.getMessage() << "\n";
                    std::cerr << "SHA256sum: "<<system(std::string("sha256sum "+std::string(std::string(std::filesystem::current_path()) + "/FTP_UPLOAD"+"/" + *FILE)).c_str())<<"\n";
                    std::cerr << "MD5sum: "<<system(std::string("md5sum "+std::string(std::string(std::filesystem::current_path()) + "/FTP_UPLOAD"+"/" + *FILE)).c_str())<<"\n";
                }
                else
                {
                    std::cout << "~~Failed to upload file " << std::string(std::string(std::filesystem::current_path()) + "/FTP_UPLOAD" + "/" + *FILE) << " from local device...~\n";
                    std::cout << "~~To " << FTP->getWorkingDirectory().getDirectory() << "...~~\n";
                    std::cerr << "STATUS: " << RESP.getStatus() << "\n";
                    std::cerr << "MESSAGE: " << RESP.getMessage() << "\n";
                }
            }
            else if (FLAG_S_P == "-s")
            {
                std::cout << "~~Uploading file " << std::string(std::string(std::filesystem::current_path()) + "/" + *FILE) << " from local device...~\n";
                std::cout << "~~To " << FTP->getWorkingDirectory().getDirectory() << "...~~\n";
                // std::string CURRENT_WORKING_DIR = system("echo $(pwd) > /dev/null");
                sf::Ftp::Response RESP = FTP->upload(std::string(std::string(std::filesystem::current_path()) + "/" + *FILE), FTP->getWorkingDirectory().getDirectory(), sf::Ftp::Binary);

                if (RESP.isOk())
                {
                    std::cout << "~~Uploaded file " << std::string(std::string(std::filesystem::current_path()) + "/" + *FILE) << " from local device...~\n";
                    std::cout << "~~To " << FTP->getWorkingDirectory().getDirectory() << "...~~\n";
                    std::cerr << "STATUS: " << RESP.getStatus() << "\n";
                    std::cerr << "MESSAGE: " << RESP.getMessage() << "\n";
                    std::cerr << "SHA256sum: "<<system(std::string("sha256sum "+std::string(std::string(std::filesystem::current_path()) +"/" + *FILE)).c_str())<<"\n";
                    std::cerr << "MD5sum: "<<system(std::string("md5sum "+std::string(std::string(std::filesystem::current_path()) +"/" + *FILE)).c_str())<<"\n";
                }
                else
                {
                    std::cout << "~~Failed to upload file " << std::string(std::string(std::filesystem::current_path()) + "/" + *FILE) << " from local device...~\n";
                    std::cout << "~~To " << FTP->getWorkingDirectory().getDirectory() << "...~~\n";
                    std::cerr << "STATUS: " << RESP.getStatus() << "\n";
                    std::cerr << "MESSAGE: " << RESP.getMessage() << "\n";
                }
            }
        }
        else
        {
            std::cout << "The given command is not correct. Please try again.\n";
        }
    }

    bool *getStatus()
    {
        return &UP_CHECK;
    }
    sf::Ftp *getFTP()
    {
        return this->FTP;
    }

    Network_Device(char *ADDRE, size_t port = 80) : PORT{port}
    {
        *ADDRESS = ADDRE;
    }

    ~Network_Device()
    {
        std::free(FTP);
        delete ADDRESS;
    }
    std::string *getFlag()
    {
        return &FLAG_S_P;
    }
};

#endif
#endif
