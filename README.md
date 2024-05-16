# Linux

1.3.2 Utilisez un logiciel de liaison série

Après "minicom -D /dev/ttyUSB0 -b 115200", on voit que 
![Capture du 2024-05-16 08-33-27](https://github.com/ZHANGENSEA/Linux/assets/149954066/d16cbd98-777d-4ad4-8f05-f86584325703)

Après Ctrl+A puis O > Configurer le port série > F, on ferme le control de port serie. 

![Capture du 2024-05-16 08-45-17](https://github.com/ZHANGENSEA/Linux/assets/149954066/74170134-2a4d-451c-b351-353bbcbd265b)

Après redémarrage du SoC, on peut voir les informations pendant cette redémarrage, par exemple, can, Net, bluetooth. Et aussi les résultats des parties, par exemple [ok] started...
A la fin, on voit "Ubuntu 16.04.2 LTS DE10-Standard ttyS0" comme le version et le système du SoC

Après df -h, on voit tous les taille du système, /dev/root est la carte SD, sa taille est 3.0G, les autres sont les systèmes.
![Capture du 2024-05-16 08-50-55](https://github.com/ZHANGENSEA/Linux/assets/149954066/4db762af-e407-4f55-b242-a909bbdf86cf)

1.3.3 Configuration réseau
Après ifconfig, on peut voir que les états des réseau, eth0 est par Ethernet, mais on ne voit pas l'ip.
![image](https://github.com/ZHANGENSEA/Linux/assets/149954066/0d888d5e-7157-456b-88b6-35df516f3834)

Ensuite, on modifie le fichier /etc/network/interfaces en utilisant les étapes dans le tp : 
![image](https://github.com/ZHANGENSEA/Linux/assets/149954066/696afcbd-a220-4a8e-a394-b7621573c4b4)

Après reboot une nouvelle fois, on voit l'ip est : 192.168.88.55
Après ping 192.168.88.55, on peut voir la communication entre le pc et le SOC.
![image](https://github.com/ZHANGENSEA/Linux/assets/149954066/6a686e9a-f8f7-41e8-8e31-81786bcb5483)

Dans le fichier sshd_config, on voit :
![image](https://github.com/ZHANGENSEA/Linux/assets/149954066/803b90da-5c9e-4b26-924d-585552e12b41)
Pour le chercher,on utilise "/Permit" ensuite "N" pour next cherche. A la fin, on utilise ":q" pour quitter vim sans modification.

Après ssh root@192.168.88.55, on voit que la connexion est bonne.
![image](https://github.com/ZHANGENSEA/Linux/assets/149954066/5138c743-ea32-4929-ad43-917f52282f33)

Ensuite on quit le minicom par Ctrl+A puis Q :
![image](https://github.com/ZHANGENSEA/Linux/assets/149954066/221d8aa4-2957-4748-bda1-5f07f5e1b9a5)

1.4.1 Exploration des dossiers 
— Répertoires présent sous la racine
![image](https://github.com/ZHANGENSEA/Linux/assets/149954066/f3f17b20-9b75-40b0-a318-c571c67c8c2f)
![image](https://github.com/ZHANGENSEA/Linux/assets/149954066/0d4ecc41-406c-41be-8cd1-413a2b3210d8)

— Dans /proc : cpuinfo, ioports, iomem. Utilisez les commandes cat, less ou more pour voir le contenu des fichiers.
1.La commande cat récupère et affiche le contenu d’un fichier dans la console Linux directement. La commande more est un outil puissant pour afficher le contenu d’un fichier tout en filtrant le résultat. La commande less est une extension des capacités de la commande more. 
2.Pour affichier le dossier ou le fichier, on a deux façons:
1) Dans le PC, on utilise "cat /proc/cpuinfo"
![image](https://github.com/ZHANGENSEA/Linux/assets/149954066/92d0eb19-bdb3-43d8-85de-8a7b534ba2b1)
2) Dans le PC, on utilise "cd /" , "ls", "cd proc/", "ls", ensuite "cat cpuinfo"
![image](https://github.com/ZHANGENSEA/Linux/assets/149954066/6942a1b5-2e87-4223-a975-b0164d0988b4)

ioports :
![image](https://github.com/ZHANGENSEA/Linux/assets/149954066/323d2305-a6dd-4a82-b329-3563bfcf294d)

iomem :
![image](https://github.com/ZHANGENSEA/Linux/assets/149954066/2f9c66b3-e345-496e-bc7e-420973374abe)

— Le répertoire /sys/class contient des entrées nouvelles (par raport à un PC classique), saurez vous les reconnaître ? En particulier, explorez les répertoires suivants :
— /sys/class/leds/fpga_ledX/
— /proc/ioport
— /proc/iomem
— /proc/device-tree/sopc@0 à comparer avec le fichier iomem
Dans le répertoire /sys/class, on a :
![image](https://github.com/ZHANGENSEA/Linux/assets/149954066/90b49c9c-728c-404a-9f79-9859243ffae2)







