/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_file.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpf <vpf@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:31:00 by vpf               #+#    #+#             */
/*   Updated: 2025/03/03 17:02:20 by vpf              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace_file.hpp"

int replace_file(std::string filename, std::string target, std::string replace)
{
    std::ifstream           inFile;
    std::ofstream           outFile;
    std::string             line;

    if (target.empty() || replace.empty())
    {
        std::cout << "Make sure that both ocurrence and replacement are valid non-zero" << std::endl;
        return (-1);
    }
    inFile.open(filename.c_str());
    if (inFile.is_open())
    {
        outFile.open((filename + ".replace").c_str(), std::ios::trunc);
        if (outFile.is_open())
        {
            while (getline(inFile, line))
            {
                size_t  pos = 0;
                while ((pos = line.find(target, pos)) != std::string::npos)
                {
                    line.erase(pos, target.size());
                    line.insert(pos, replace);
                    pos += replace.size();
                }
                outFile << line << std::endl;
            }
            outFile.close();
        }
        else
        {
            inFile.close();
            std::cout << "Error opening outFile" << std::endl;
            return (-1);
        }
        inFile.close();
    }
    else
    {
        std::cout << "Error opening inFile" << std::endl;
        return (-1);
    }    
    return (0);
}
