.class public Exemplo1
.super java/lang/Object

.method public <init>()V
   aload_0

   invokenonvirtual java/lang/Object/<init>()V
   return
.end method

.method public static main([Ljava/lang/String;)V
   .limit stack 20
   .limit locals 5

   getstatic java/lang/System/out Ljava/io/PrintStream;
   ldc "Valor de A:"
   invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
   getstatic java/lang/System/out Ljava/io/PrintStream;
   ldc "Valor de B:"
   invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
   iload 1
   iload 4
   if_icmpne l-1
   goto l-1
   iload 1
   iload 4
   if_icmpgt l1
   goto l2
l1:
   iload 1
   iload 4
   isub
   istore 1
l2:
   iload 4
   iload 1
   if_icmpgt l3
   goto l4
l3:
   iload 4
   iload 1
   isub
   istore 4
l4:
   getstatic java/lang/System/out Ljava/io/PrintStream;
   ldc "\nRes="
   invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
   getstatic java/lang/System/out Ljava/io/PrintStream;
   iload 1
   invokevirtual java/io/PrintStream/print(I)V

return
.end method