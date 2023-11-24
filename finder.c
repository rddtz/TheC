#include <stdio.h>

int main(){

    char texto_maior[2000] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed pretium mollis purus, ac rhoncus dolor lacinia vitae. Vivamus turpis dui, ullamcorper sit amet mattis quis, mollis eu enim. Phasellus quis aliquet quam. Vivamus pharetra cursus neque eu placerat. Cras congue lectus id auctor faucibus. Fusce faucibus quam nibh, et aliquam lorem varius eu. Integer ultrices at mi id condimentum. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur egestas vel augue ut pulvinar. Aenean pharetra a lectus sit amet consequat. Suspendisse nec auctor nulla. Nunc elit nibh, commodo sit amet nunc sit amet, dignissim placerat ipsum. Nunc consectetur ut turpis et facilisis. Cras pulvinar urna nec dolor tempor, eget elementum urna ultrices. Nam consequat efficitur justo. Phasellus non nibh mi. Aenean bibendum nulla et dui pellentesque, ac venenatis ex feugiat. In libero erat, maximus non malesuada vitae, bibendum ut velit. Fusce laoreet vestibulum tincidunt. Duis vel metus luctus metus rutrum posuere. Quisque est urna, finibus sit amet tortor in, laoreet consectetur justo. Phasellus suscipit sagittis pharetra. Morbi pellentesque molestie dui sit amet malesuada. Aenean varius fermentum nisl in lobortis. Aenean congue a neque eget efficitur. Curabitur scelerisque felis nec risus varius euismod maximus ac enim. Nullam vitae augue non felis semper tempor. Nunc ac dignissim enim, ac ornare risus. Donec consequat tincidunt convallis. Ut quam diam, fermentum vehicula nunc et, pulvinar suscipit orci. Suspendisse ac felis sit amet nunc vulputate tristique ac ut justo. Sed dignissim eros augue, eget semper orci eleifend ac. Vestibulum quis maximus magna. Praesent nec justo iaculis, rutrum tortor et, pharetra est. Vestibulum posuere porta metus. Nam a turpis non nulla aliquet tincidunt. Nam neque quam, mattis quis pharetra sit amet, vestibulum eget nisl. Nam aliquam elementum volutpat. Integer commodo velit sed arcu consectetur tincidunt. Pellentesque id aliquam ligula. Vestibulum leo turpis, pellentesque porttitor sollicitudin et, molestie sed lacus. Aenean bibendum varius posuere. Nulla a ultrices lorem, ut porttitor nisi. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec sagittis hendrerit nisi lobortis fermentum. In sit amet lectus lobortis massa condimentum tincidunt. Sed faucibus risus nunc, sit amet suscipit lacus tincidunt scelerisque. Nunc nec porta enim.";
    char texto_menor[100] = "Lorem ipsum";
    int inicio, fim;
    int j, k;

    j = k = inicio = fim = 0;

    while(!fim && j < 2000){

        inicio = j;
        while((texto_maior[j+k] == texto_menor[k]) && (texto_menor[k] != '\0'))
            k++;
            if(texto_menor[k] == '\0'){
                fim = j+k;
            }
        j++;
        k = 0;

    }

    printf("Inicia em: %d\nTermina em: %d\n", inicio, fim);

    return 0;
}
