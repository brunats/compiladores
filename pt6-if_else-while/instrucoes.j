.class public teste
.super java/lang/Object

.method public <init>()V
   aload_0

   invokenonvirtual java/lang/Object/<init>()V
   return
.end method

.method public static main([Ljava/lang/String;)V
   .limit stack 20
   .limit locals 4

   iconst_1
   istore 1
   iconst_1
   istore 2
   iload 1
   iload 2
   isub
   istore 3

return
.end method