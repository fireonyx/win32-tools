<script lang="ts">
	let canvas: HTMLCanvasElement;
    let attached = false;
    let ctx: CanvasRenderingContext2D;

	setTimeout(() => {
		ctx = canvas.getContext("2d");
		attached = true;
	}, 200);
</script>

<section class="shield">
	<section class="view">
		<canvas class="emulatorView" bind:this={canvas} />
	</section>

	<section class="emulator-sidebar">
		<button>Boot Emulator STAGE 1</button>
	</section>
</section>

<style lang="scss">
@import "../Config.scss";

.shield {
  display: flex;
  flex-direction: row;

  .view {
	canvas {
	  border: 1px solid #222;
	  width: calc(100vw - 60px - 10px - 320px - 10px);
	  border-radius: 4px;
	  height: calc((100vw - 60px - 10px - 320px - 10px) * 9 / 16);
	  max-height: calc(100vh - 60px - 10px - 10px);
	  max-width: calc((100vh - 60px - 10px - 10px) * 16 / 9);
	}
  }
}
</style>