#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
 pid_t child1, child2,child3;
 int child_status;
 int t;

         printf("\nBài tập lớn học phần Hệ Điều Hành");
         printf("\n");
	 printf("\nThàn viên nhóm  02: ");
         printf("\n");
	 printf("\nĐỗ Văn Đại            20150796   DT-08    K60  ");
         printf("\nPhạm Thế Anh          20140207   DT-10    K59  ");       
	 printf("\nNguyễn Hoàng Bách     20140304   DT-06    K59  ");

        sleep(5);

 // Tạo tiến trình con
// Tien trinh 1. Ma hoa video dai1

child1 = fork();
	 switch ( child1 ) {
	 case -1:                                                         // Tạo tiến trình con bị lỗi.
	 printf("\n Tao tien trinh con bi loi");
	 exit( 1 );
	 case 0:         
         system("ffmpeg -i dai1.mp4 -vf scale=1280:-1 -c:v libx264 -preset veryslow -crf 24 dai.mp4");                       
         system("ffmpeg -i dai.mp4 dai.mpeg");                            //Convert video sang chuẩn MPEG4
	 sleep( 3 );                                                      // Mã lỗi trả về của tiến trình con.
	 default:                                                         //Day la tiến trình cha
	 printf("\nĐã nén xong,Tiến trình con 1 hoàn thành");

	 sleep(5);
	 }

	
//Tiến trình 2 chạy video dai.mpeg của tiến trình 1 và tự mã hóa vieo anh2.mp4 của mình

 child2 = fork();
	 switch ( child2 ) {
	 case -1:                                                    // Tạo tiến trình con bị lỗi.
	 printf("\nKhong the tao tien trinh moi");
	 exit( 1 );
	 case 0:                                                     //Tạo tiến trình con thành công.
	 system("ffplay dai.mpeg");                                  //phát video của tiến trình 1.
	 getppid() ;                                                //fork trả về giá trị 1 khi tiến trình con bị giết.
	 exit( 0 ); // Mã lỗi trả về của tiến trình con
  
         

	 default:                                                 // fork thành công, chúng ta đang ở trong tiến trình cha

	 sleep(12);                                                //sau 1s thì giết tiến trình phát video 
	system ("pkill ffplay");
        printf("\nVideo dài 4 phút với dung lượng\n");
        system("du -ah dai.mpeg");                                   //Tính dung lượng video bằng câu lệnh 
        sleep(3);
 // Sau do ma hoa video cua chính mình. 
         system("ffmpeg -i anh2.mp4 -vf scale=1280:-1 -c:v libx264 -preset veryslow -crf 24 anh.mp4");                       
         system("ffmpeg -i anh.mp4 anh.mpeg");                            //Convert video sang chuẩn MPEG4
	 printf("\nTiến trình 2 đã hoàn thành.\n");
         printf("\nMời tiến trình tiếp theo.\n");
         sleep(5);
	 }

	
 child3 = fork();
	 switch ( child3 ) {
	 case -1:                                                    // Tạo tiến trình con bị lỗi.
	 printf("\nKhong the tao tien trinh moi");
	 exit( 1 );
	 case 0:                                                     //Tạo tiến trình con thành công.
	 system("ffplay anh.mpeg");                                  //phát video của tiến trình 1.
	 getppid() ;//fork trả về giá trị 1 khi tiến trình con bị giết.
	 exit( 0 ); // Mã lỗi trả về của tiến trình con
  
         

	 default: // fork thành công, chúng ta đang ở trong tiến trình cha

	 sleep(12); //sau 12s thì giết tiến trình phát video 
	system ("pkill ffplay");
        printf("\nVideo dài 4 phút với dung lượng\n");
        system("du -ah dai.mpeg");                                   //Tính dung lượng video bằng câu lệnh 
        sleep(3);

// Sau do ma hoa video cua chính mình.
         system("ffmpeg -i bach3.mp4 -vf scale=1280:-1 -c:v libx264 -preset veryslow -crf 24 bach.mp4");                       
         system("ffmpeg -i bach.mp4 bach.mpeg");                            //Convert video sang chuẩn MPEG4
	 printf("\nTiến trình con 3 đã hoàn thành.\n");
         sleep(5);
	 }
  


	 printf("Thanh vien		Dong gop(%)\n");
	 printf("Dai      		 33.33% \n");
         printf("The Anh                 33.33% \n");
         printf("Bach                    33.33% \n");
	 exit( 0 ); 
 return ( 0 );
}
