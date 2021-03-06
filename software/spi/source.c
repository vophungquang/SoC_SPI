#include "alt_types.h"
#include "altera_avalon_spi_regs.h"
#include "altera_avalon_spi.h"
#include "system.h"
#include <stdio.h>
#include <unistd.h>// usleep
int main(void){
printf("Entered Main\n");
alt_u8 send_M; alt_u8 send_S; alt_u8 rcvd_S; alt_u8 rcvd_M; alt_u8 count;
count = 0;
while(1){
send_M = 0xAA;
send_S = 0x55;

IOWR_ALTERA_AVALON_SPI_CONTROL(SPI_MASTER_BASE, 0x00);
IOWR_ALTERA_AVALON_SPI_CONTROL(SPI_SLAVE_BASE, 0x00);

IOWR_ALTERA_AVALON_SPI_TXDATA(SPI_SLAVE_BASE, send_S);
IOWR_ALTERA_AVALON_SPI_TXDATA(SPI_MASTER_BASE, send_M);

usleep(75);

rcvd_S = IORD_ALTERA_AVALON_SPI_RXDATA(SPI_SLAVE_BASE);
rcvd_M = IORD_ALTERA_AVALON_SPI_RXDATA(SPI_MASTER_BASE);
// Print results
printf("master sent = %i\tslave recv'd = %i\n", send_M, rcvd_S);
printf("slave sent = %i\tmaster recv'd = %i\n", send_S, rcvd_M);

count ++;
usleep(1000000);
}
return 0;
}
