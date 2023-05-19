#include <stdio.h>
#include <math.h>



typedef struct {

        double x;
        double y;
        double z;

    }vector;
    
double find_orthogonol(vector vector1, vector vector2, vector* vec_out);

int main(){

  
    vector vec_1  ={1,2,3};
    vector vec_2 = {2,1,-1};

    vector vec_out;
    double angle;

    angle = find_orthogonol(vec_1, vec_2, &vec_out);
    printf("\n Angle : %lf\n", angle);
    
    printf("%lf,%lf,%lf\n", vec_out.x, vec_out.y, vec_out.z);

}






  double find_orthogonol(vector vec_1, vecto\ vec_2, vector* vec_out ){

      double dot_product = vec_1.x * vec_2.x + vec_1.y * vec_2.y + vec_1.z * vec_2.z;
      double squared_vec1 = sqrt(vec_1.x * vec_1.x + vec_1.y * vec_1.y + vec_1.z * vec_1.z);
      double squared_vec2 = sqrt(vec_2.x * vec_2.x + vec_2.y * vec_2.y + vec_2.z * vec_2.z);


      //convert
      double angle = acos(dot_product /(squared_vec1 * squared_vec2)) * 180 / M_PI;

      vec_out->x = vec_1.y * vec_2.z - vec_1.z * vec_2.y;
      vec_out->y = vec_1.z * vec_2.x - vec_1.x * vec_2.z;
      vec_out->z = vec_1.x * vec_2.y - vec_1.y * vec_2.x;

      return angle;
  
}
