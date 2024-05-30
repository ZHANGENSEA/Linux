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
Pour configurer les leds, il faut lier le carte VEEK par minicom, ensuite on peut changer l'état de leds par terminal (0 étaint, 1 allume):
![image](https://github.com/ZHANGENSEA/Linux/assets/149954066/8a90d248-5184-4b8f-a59a-0d9ef53bd038)

1.4.3 Hello world 
D'abord, il faut choisir le "Dossiers partagés" dans le bon source par "Configuration" de VM. Ensuite "pwd" pour savoir ou l'on se situe puis "cd src/"(car le point de montage est : src, comme dans la photo ci-dessous), "ls" et on peut voir notre fichier "hello.c", puis en utilisant le command "arm-linux-gnueabihf-gcc hello.c -o hello.o", le hello.c est bien compilé. On peut voir le fichier "hello.o" a été créé automatiquement.
![image](https://github.com/ZHANGENSEA/Linux/assets/149954066/5e03ee07-c733-4a01-a652-cd9d209199c6)

Après complication, on utilise "scp hello.o root@192.168.88.55:~/" pour copier le fichier hello.o sur la carte VEEK. Puis "./hello.o" sur terminal pour éxcuter le programme hello.c. Le résultat est :
![image](https://github.com/ZHANGENSEA/Linux/assets/149954066/d4bb0ab6-33ff-4106-8531-596e8c4d3388)
![image](https://github.com/ZHANGENSEA/Linux/assets/149954066/87d9fda6-aab2-4744-a9f9-f7154462675f)

1.4.4 Accès au matériel
On a fait dans la partie 1.4.1.

1.4.5 Chenillard 
On le fait led.c et réalsé correcetment.

2 Modules kernel (TP2)
2.1 Accès aux registres
![image](https://github.com/ZHANGENSEA/Linux/assets/149954066/9904fe4c-63ec-4386-bb82-f0cf1fa5fd10)
On voit que le LED8 s'allume.
Problèmes et limites : 

2.2 Compilation de module noyau sur la VM
Arpès installation du "sudo apt install linux-headers-amd64" et "sudo apt install bc". On telecharge le dossier sur Moodle et le renomme comme "module", ensuite dans VM, "ls", "cd module" et "make", puis on trouve que le fichier "hello.ko" a bien créé. 

On utilise sudo modinfo hello.ko pour voir les informations :
![image](https://github.com/ZHANGENSEA/Linux/assets/149954066/f678f456-36bc-433e-b135-02502160a868)

On utilise sudo lsmod pour lister les modules chargés : 
![image](https://github.com/ZHANGENSEA/Linux/assets/149954066/f1cf7416-d806-4ee5-9f00-c267a9e61078)

-utilisation de paramètres au chargement du module
Pour l'utilisation de paramètres au chargement du module, on a mis le paramètre = 3 dans le code hello.c, ensuite on a récupéré le paramètre de ce module  = 0. Puis on a utilisé "sudo insmod hello.ko param = 2" pour changer le paramètre à 2. Avec "sudo dmesg", on peut voir le résultat de parmètre et toutes les affichages:
![image](https://github.com/ZHANGENSEA/Linux/assets/149954066/e1b8958c-395f-43cd-9603-510a79371909)

-création d’un entrée dans /proc
D'abord, accès au fichiers :
![image](https://github.com/ZHANGENSEA/Linux/assets/149954066/2bf90e89-49cf-406f-9a80-45144e94f592)

Ensuite, on crée les fonction read et write :
![image](https://github.com/ZHANGENSEA/Linux/assets/149954066/a137f751-dd59-4af8-b11e-800954431772)

Oubliez pas ajouter les include et déclaration des variables :
![image](https://github.com/ZHANGENSEA/Linux/assets/149954066/7878bd39-8cf6-4c80-a4a9-32aaf2f069d9)

Après l'complié, on ecrit "bonjour" dans test par le command "echo "bonjour" > /proc/ensea/test" dans VM, ensuite, on utilise "sudo dmesg" et on voit le message"bonjour".
![image](https://github.com/ZHANGENSEA/Linux/assets/149954066/e0c0ed62-87ec-4121-9222-ec5e563bfe01)

-utilisation d’un timer
On ouvrte le fichier "time_module.c" et réarmer le tiler dans la fonction de gestion pour un timer périodique :
![image](https://github.com/ZHANGENSEA/Linux/assets/149954066/8753140c-6e23-46e4-88a7-88fa75aec4d4)

Ensuite on compile time_module.c et on voit le timer a été bien périodique.

2.3 CrossCompilation de modules noyau

2.3.2 Récupéreation de la configuration actuelle du noyau

On décompresse le fichier config.gz dans le dossier : /home/ensea/linux-socfpga et renomme le en .config par le commande "gunzip config.gz" et "mv config .config" :
![image](https://github.com/ZHANGENSEA/Linux/assets/149954066/7449d7f4-362d-41d9-a25e-799cc166967d)

Puis on lance les commandes depuis le dossier /home/ensea/linux-socfpga
![image](https://github.com/ZHANGENSEA/Linux/assets/149954066/1da5a55f-eeb9-4975-a94a-da69c213ad53)

— Quel est le rôle des lignes commençant par export ?
Pour créer les variables CROSS_COMPILE et ARCH ce que on utilise dans prepare et scripts.

— Pourquoi le chemin fini par un tiret "-" ?









