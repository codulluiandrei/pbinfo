void FNume(char s[], char id[])
{
    char *p = strchr(s, ' ');
    strcpy(id, p + 1);
    strcat(id, "2022\0");
}