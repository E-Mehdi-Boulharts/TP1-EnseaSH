# TP1-EnseaSH
Ce readme est un bref compte rendu des 8 premières heures de TP de synthèse.

Dans la question 1 nous avons à l'aide de la fonction write écrit un message d'acceuil. Nous avons par ailleurs fait également une partie de la question 2 et 3 car nous avons mis l'option d'exit sur notre code.

Dans la question 2 nous avons pu utiliser la fonction read afin de faire le lien entre l'utilisateur et la machine. 

Dans la question 3 nous avons donc réutiliser ce que nous avions fait précedemment pour faire "exit" le programme.

Dans la question 4 il est question de d'éxécuter un programme que l'utilisateur a au préalable choisi (par l'intermédiaire de read). Nous n'avions pas compris cette partie de la question et nous l'avons fait uniquement pour une fonction qui est fortune. Mais nous ne pouvons pas simplement éxécuter cette fonction sans que le programme s'arrête. Il faut faire un fork afin que un fils puisse éxécuter la commande et ainsi pouvoir retourner sur le père et attendre de nouvelle instruction.

Dans la question 5 nous devions calculer le temps d'éxécution d'une commande. L'objectif n'a pas été réalisé. Nous avons utilisé clock_gettime afin d'avoir notre début et fin du timer. Sachant que c'est notre fils qui éxécute la commande (dans notre cas uniquement fortune), nous avons positionner le début avant que le fils ne se crée et la fin après sa mort. L'affichage du temps était parfois cohérente en ms et la plupart du temps abbérante avec des temps négatif.

Enfin lors de ces séances nous avont pu nous refamiliariser avec les fonctions write et read qu'on avait vu en réseau. Nous avons également pu utiliser le fork afin de "sous-traiter" des actions dans notre programme.
