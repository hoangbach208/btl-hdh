#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
int main(void)
{
 pid_t child_1, child_2,child_3;
 int child_status;
 int n;

/*
* Thong tin sinh vien 
*/

	 printf("\nThanh vien nhom 02: ");
	 printf("\nHo va ten        MSSV      Lop     Khoa ");
	 printf("\nDo Van Dai     20150796   DT-08    K60: ");
	
	 	

	sleep (5);
 // Tạo tiến trình con

	/*
	* Nén video H264
	*/

child_1 = fork();
	 switch ( child_1 ) {
	 case -1: // fork không tạo được tiến trình mới
	 printf("\nKhong the tao tien trinh moi");
	 exit( 1 );
	 case 0: // fork thành công, chúng ta đang ở trong tiến trình con

	 system( "ffmpeg -i kich.mp4 -vf scale=1280:-1 -c:v libx264 -preset veryslow -crf 24 -strict -2 			output.mp4" );
	// sleep( 3 );

	 exit( 0 ); // Mã lỗi trả về của tiến trình con

	 default: // fork thành công, chúng ta đang ở trong tiến trình cha
	 sleep(10);
	 system ("killall ffmpeg");
	 printf("Nen xong, tien trinh con 1 hoan thanh.\n");
	// wait( &child_status );

	 sleep(5);
	 }

	/*
	* Play back
	*/

 child_2 = fork();
	 switch ( child_2 ) {
	 case -1: // fork không tạo được tiến trình mới
	 printf("\nKhong the tao tien trinh moi");
	 exit( 1 );
	 case 0: // fork thành công, chúng ta đang ở trong tiến trình con

	 system("ffplay kich.mp4"); //phát video
	
	 getppid() ;//fork trả về giá trị 1 khi tiến trình con bị giết.

	 exit( 0 ); // Mã lỗi trả về của tiến trình con

	 default: // fork thành công, chúng ta đang ở trong tiến trình cha

	for(n=0;n<10;n++){
	 printf("Dung luong RAM VA CPU la:\n");	
	 printf("RAM %d= %d\n",n);	
	 printf("CPU %d= %d\n",n);	
	sleep(3);		
	
	}
	 sleep(10); //sau 10s thì giết tiến trình phát video 
	 system ("killall ffplay");
	
	 printf("Tien trinh con 2 hoan thanh.\n");
	 }

	/*
	* Hiển thị dung lượng, time phát
	*/

child_3 = fork();
	 switch ( child_3 ) {
	 case -1: // fork không tạo được tiến trình mới
	 printf("\nKhong the tao tien trinh moi");
	 exit( 1 );
	 case 0: // fork thành công, chúng ta đang ở trong tiến trình con
	
	 printf("Dung lượng video là :\n");
	 system("du -ah kich.mp4");

	 printf("Thoi gian phat video : \n");
	// system ("mediainfo --Inform="Video;%Duration/String3%" kich.mp4");
	
	getppid() ; //fork trả về giá trị 1 khi tiến trình con bị giết.

	 exit( 0 ); 

	 default: // fork thành công, chúng ta đang ở trong tiến trình cha

	 sleep(2);

	 printf("Tien trinh con 3 hoan thanh.\n");
	 }

	/*
	* Dong gop cac thanh vienDai
	*/
	 printf("Thanh vien		Dong gop(%)\n");
	 printf("Do Van 		a% \n");
	 
	 exit( 0 ); 
 return ( 0 );
}
