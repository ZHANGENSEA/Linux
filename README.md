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
Après ifconfig, on peut voir que les états des réseau, eth0 est par Ethernet, ip est 2a:7d:e9:d6:29:e4
![image](https://github.com/ZHANGENSEA/Linux/assets/149954066/0d888d5e-7157-456b-88b6-35df516f3834)

Ensuite, on modifie le fichier /etc/network/interfaces en utilisant les étapes dans le tp : 
![image](https://github.com/ZHANGENSEA/Linux/assets/149954066/696afcbd-a220-4a8e-a394-b7621573c4b4)

Après reboot une nouvelle fois, on voit l'ip est : 192.168.88.55
