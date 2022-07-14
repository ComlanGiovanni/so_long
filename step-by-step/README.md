MacOS

   ~ git clone https://github.com/42Paris/minilibx-linux.git mlx
   ~ Brew install Xquartz

Reboot computer

touch main.c and follw step by step and comment

gcc -Wall -Wextra -Werror -g -o tuto -L. libmlx.a -lXext -lX11 test.c -framework OpenGL -framework AppKit && ./tuto

