#include <iostream>
#include <fstream>


int main ()
{
    std::ofstream ofs;
    ofs.open("cellZones");
    if (!ofs.is_open()){
        std::cout << "Failed to open file.\n";
	return 1;
    }
    
    std::cout << "PLease input the cell number:\n";
    int N, offset;
    std::cin >> N;
    std::cout << "Please input the offset number:\n"; 
    std::cin >> offset;

    ofs << "/*--------------------------------*- C++ -*----------------------------------*\\\n";
    ofs << "| =========                 |                                                 |\n";
    ofs << "| \\\\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox           |\n";
    ofs << "|  \\\\    /   O peration     | Version:  2206                                  |\n";
    ofs << "|   \\\\  /    A nd           | Website:  www.openfoam.com                      |\n";
    ofs << "|    \\\\/     M anipulation  |                                                 |\n";
    ofs << "\\*---------------------------------------------------------------------------*/\n";

    ofs << "FoamFile\n";
    ofs << "{\n    version    2.0;\n    format     ascii;\n";
    ofs << "    arch       \"LSB;label=32;scalar=64\" \n";
    ofs << "    class       regIOobject;\n";
    ofs << "    location   \"constant/polyMesh\";\n";
    ofs << "    object      cellZones;\n";    
    ofs << "    meta\n    {\n        names           1 ( rotor );\n    }\n\n}\n";

    ofs << "\n\n1\n(rotor\n{\n    type        cellZone;\n    cellLabels    List<label>\n";

    ofs << N << "\n(\n";
   
    for (int i = 0; i < N; i++){
        ofs << "        " << i + offset << "\n";
    }	

    ofs  << ")\n;\n}\n)\n";
    ofs.close();

    return 0;
}
