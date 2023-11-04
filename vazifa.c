/*     k25     */

// #include<stdio.h>
// #include<string.h>

// int unli(char a){
//     if (a == 'a' || a == 'o' || a == 'i' || a == 'u' || a == 'e' || a == 'A' || a == 'O' || a == 'I' || a == 'U' || a == 'E'){
//         return 0;
//     }
//     return 1;
    
// }

// int main(){

//     char input[50]="\0";
//     char output[50]="\0";
//     char box[50]="\0";
//     int j=0;

//     scanf("%[^\n]s",input);

//     for (int i = 0; input[i]!='\0'; i++){
//         if (unli(input[i])){
//             output[j++]=input[i];
//         }
//     }
    
//     puts(output);
// }






/*     k26      */

// #include<stdio.h>
// #include<ctype.h>

// int main(){

//     char matn[50];

//     fgets(matn,sizeof(matn),stdin);
//     int j=0,k=0;

//     for (int i = 0; matn[i]!='\n'; i++){
        
//         if (matn[i]!=' ' && (matn[i+1]==' ' || matn[i+1]=='\n')){
//             k=j;
//             for (; j <= i; j++){
//                 if (isdigit(matn[j])){
//                     for (; k <= i; k++){
//                         printf("%c",matn[k]);
//                     }
//                     printf(" ");
//                 } 
//             }
//             j=i+1;
            
//         }
//     }
// }







/*     k27      */

// 